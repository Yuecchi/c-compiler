#include <stdlib.h>
#include <string.h>

#include "mips.h"
#include "tac.h"
#include "sym_tbl.h"
#include "type.h"

// Allocates a register for a value
int get_val_reg(char *temp) {
	return (temp[strlen(temp) - 1] - '0') % 10;
}

// Allocates a register for a memory address
int get_adr_reg(char *temp) {
	return (temp[strlen(temp) - 1] - '0') % 4;
}

// Calculates the offset from the frame pointer required
// to find a certain array element on the stacks
int get_fp_offset(char* temp) {
	char *c_offset = &(temp[4]);
	char *pch = strchr(c_offset, ')');
	pch = '\0';
	return atoi(c_offset);		
}

// Generates the header for mips programs. The header includes 
// global variables from the source program and a pair of runtime
// functions which assist with the operation of functions
void mips_header(FILE *dst, FILE *src) {
	char buf[32];
	
	// static (global) variables
	fprintf(dst, "\t.data\n");
	
	// implicit newline constant
	fprintf(dst, "newline:\t .asciiz \"\\n\"\n");
	
	// statically allocate global variables and arrays
	while (fgets(buf, sizeof buf, src)) {
		buf[strlen(buf) - 1] = '\0';
		char *token = strtok(buf, " ");
		int type    = atoi(strtok(NULL, " "));
		if (type == INT) {
			int val = atoi(strtok(NULL, " "));
			fprintf(dst, "%s:\t.word %i\n", token, val);	
		} else if (type == ARRAY) {
			fprintf(dst, "%s:\t.word", token);
			int elements = atoi(strtok(NULL, " ")) / 4;
			char *ele = strtok(NULL, " ");
			for (int i = 0; i < elements; i += 1) {
				if (ele) {
					fprintf(dst, " %s,", ele);
					ele = strtok(NULL, " ");
				} else {
					fprintf(dst, " 0,");
				}
			}
			fprintf(dst,"\n");
		}
	}
	fprintf(dst, "\t.text\n");
	
	/* runtime funtions */
	
	// sub routine for storing registers and fp
	fprintf(dst, "save_frame:\n");
	fprintf(dst, "\taddi $sp, $sp, -44\n");
	for (int i = 0; i < 10; i += 1) {
		fprintf(dst, "\tsw $t%i, %i($sp)\n", i, 44 - (i * 4));
	}
	fprintf(dst, "\tsw $fp, 4($sp)\n");
	fprintf(dst, "\tjr $ra\n");	

	// sub routine for restoring registers and fp
	fprintf(dst, "load_frame:\n");
	for (int i = 0; i < 10; i += 1) {
		fprintf(dst, "\tlw $t%i, %i($sp)\n", i, 44 - (i * 4));
	}
	fprintf(dst, "\tlw $fp, 4($sp)\n");
	fprintf(dst, "\taddi $sp, $sp, 44\n");
	fprintf(dst, "\tjr $ra\n");		
}

// generates code for assignment operations
void mips_assign(quad *qd, FILE *dst) {
	int val_reg, adr_reg, idx_reg, offset;
	if (is_temp(qd->result)) {
		if (is_int(qd->arg1)) { /* $tn = INTEGER */
			val_reg = get_val_reg(qd->result);
			fprintf(dst, "\tli $t%i, %s\n", val_reg, qd->arg1); // load immediates
		} else if (!strcmp(qd->arg1, "call")) { /* $tn = call func */
			val_reg = get_val_reg(qd->result);
			qd->arg1 = qd->arg2;
			mips_call(qd, dst);	
			fprintf(dst, "\tmove $t%i, $v1\n", val_reg); // assign return value
		} else if (is_fp(qd->arg1)) { /* $tn = $fp(k) */
			val_reg = get_val_reg(qd->result);
			offset  = get_fp_offset(qd->arg1);
			if (qd->arg2) { /* _tn_ = $fp(k)[m] */
				idx_reg = get_val_reg(qd->arg2);
				// get position of element in stack
				fprintf(dst, "\tsll $t%i, $t%i, 2\n", idx_reg, idx_reg);
				fprintf(dst, "\taddi $t%i, $t%i, %i\n", idx_reg, idx_reg, offset);
				// manipulate fp to locate element and load value
				fprintf(dst, "\tmove $v0, $fp\n");
				fprintf(dst, "\tsub $v0, $v0, $t%i\n", idx_reg);
				fprintf(dst, "\tlw $t%i, ($v0)\n", val_reg);
			} else {
				fprintf(dst, "\tlw $t%i, -%i($fp)\n", val_reg, offset);
			}
		} else { /* _tn_ = x */
			val_reg = get_val_reg(qd->result);
			adr_reg = get_adr_reg(qd->result);
			fprintf(dst, "\tla $a%i, %s\n", adr_reg, qd->arg1); // load address
			if (qd->arg2) { /* _tn_ = x[m] */
				idx_reg = get_val_reg(qd->arg2);
				fprintf(dst, "\tsll $t%i, $t%i, 2\n", idx_reg, idx_reg);
				fprintf(dst, "\tadd $a%i, $a%i, $t%i\n", adr_reg, adr_reg, idx_reg);
			}
			fprintf(dst, "\tlw $t%i, ($a%i)\n", val_reg, adr_reg); // load word
		}
	} else if (is_fp(qd->result)) { /* $fp(k) = _tn_ */
		val_reg = get_val_reg(qd->arg1);
		offset = get_fp_offset(qd->result);
		if (qd->arg2) { /* $fp(k)[m] = _tn_ */
			idx_reg = get_val_reg(qd->arg2);
			// get position of element in stack
			fprintf(dst, "\tsll $t%i, $t%i, 2\n", idx_reg, idx_reg);
			fprintf(dst, "\taddi $t%i, $t%i, %i\n", idx_reg, idx_reg, offset);
			// manipulate fp to locate element and store value
			fprintf(dst, "\tmove $v0, $fp\n");
			fprintf(dst, "\tsub $v0, $v0, $t%i\n", idx_reg);
			fprintf(dst, "\tsw $t%i, ($v0)\n", val_reg);
		} else {
			fprintf(dst, "\tsw $t%i, -%i($fp)\n", val_reg, offset);
		}
	} else { /* x = _tn_ */
		val_reg = get_val_reg(qd->arg1);
		adr_reg = get_adr_reg(qd->arg1);
		fprintf(dst, "\tla $a%i, %s\n", adr_reg, qd->result); // load address
		if (qd->arg2) { /* x[m] = _tn_ */
			idx_reg = get_val_reg(qd->arg2);
			fprintf(dst, "\tsll $t%i, $t%i, 2\n", idx_reg, idx_reg);
			fprintf(dst, "\tadd $a%i, $a%i, $t%i\n", adr_reg, adr_reg, idx_reg);
		}
		fprintf(dst, "\tsw $t%i, ($a%i)\n", val_reg, adr_reg); // store word
	}
}

// generates code for addition operations
void mips_add(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tadd $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

// generates code for subtraction operations
void mips_sub(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsub $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

// generates code for is equal operations
void mips_equal(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tseq $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);	
}

// generates code for great than or equal to operations
void mips_greater_than_or_equal(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsge $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

// generates code for greater than operations
void mips_greater_than(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsgt $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

// generates code for less than or equal to operations
void mips_less_than_or_equal(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsle $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

// generates code for less then operations
void mips_less_than(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tslt $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);	
}

// generates code fornot equal operations
void mips_not_equal(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsne $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);		
}

// generates code for conditional jumps
void mips_cond_jump(quad *qd, FILE *dst) {
	int val_reg = get_val_reg(qd->arg1);
	fprintf(dst, "\tbeqz $t%i, %s\n", val_reg, qd->result);
}

// generates code for undconditional jumps
void mips_jump(quad *qd, FILE *dst) {
	fprintf(dst, "\tj %s\n", qd->arg1);
}

// generates code from print operations
// all prints include an implcit trailing newline
void mips_print(quad *qd, FILE *dst) {
	int val_reg = get_val_reg(qd->arg1);
	fprintf(dst, "\tmove $a0, $t%i\n", val_reg);
	fprintf(dst, "\tli $v0, 1\n");
	fprintf(dst, "\tsyscall\n");
	fprintf(dst, "\tla $a0, newline\n");
	fprintf(dst, "\tli $v0, 4\n");
	fprintf(dst, "\tsyscall\n");
}

// generates code for program termination
void mips_terminate(quad *qd, FILE *dst) {	
	fprintf(dst, "\tli $v0, 10\n");
	fprintf(dst, "\tsyscall\n");
}

// generates code for function returns
void mips_return(quad *qd, FILE *dst) {
	// load return address from stack
	fprintf(dst, "\tlw $ra, 0($fp)\n");
	// either return the desired value or return 0
	// if no value was given
	if (qd->arg1) {
		int val_reg = get_val_reg(qd->arg1);
		fprintf(dst, "\tmove $v1, $t%i\n", val_reg);
	} else {
		fprintf(dst, "\tli $v1, 0\n");
	}
	// pop the stack frame and return
	fprintf(dst, "\tmove $sp, $fp\n");
	fprintf(dst, "\tjr $ra\n");
}

// generates code that affects the stack
void mips_push(quad *qd, FILE *dst) {
	char* arg1 = qd->arg1;
	int val_reg, offset; 
	if (*arg1 == '$') {
		switch(*(arg1 + 1)) {
			case 'f': /* create new stack frame */
				fprintf(dst, "\tjal save_frame\n");
				// store location which will be the 
				// top of the new stack frame
				fprintf(dst, "\tmove $v1, $sp\n");
				break;
			case 's': /* create stack frame for main function */
				// initialize the frame pointer
				fprintf(dst, "\tmove $fp, $sp\n");
				// allocate stack space for the main function's local variables
				symbol_t sym = *(get_symbol("main"));
				if (sym.value) {
					fprintf(dst, "\taddi $sp, $sp, -%i\n", 4 + (4 * sym.value));
				}
				break;
			case 'r': /* push return address to stack */
				fprintf(dst, "\tsw $ra, 0($fp)\n");
				break;
			default: /* t (params) */
				val_reg = get_val_reg(qd->arg1);
				offset = atoi(qd->arg2);
				fprintf(dst, "\taddi $sp, $sp, -4\n");
				fprintf(dst, "\tsw $t%i, 4($sp)\n", val_reg);
				break;
		}
	} else {
		int size = atoi(qd->arg1);
		fprintf(dst, "\taddi $sp, $sp, -%i\n", size);
	}
}

// generates code to perform function calls
void mips_call(quad *qd, FILE *dst) {
	// move fp to top of new stack frame
	fprintf(dst, "\tmove $fp, $v1\n");
	// allocate space for local variables
	symbol_t symbol = *(get_symbol(qd->arg1));
	if (symbol.value) {
		fprintf(dst, "\taddi $sp, $sp, -%d\n", 4 * symbol.value);
	}
	// call function
	fprintf(dst, "\tjal %s\n", qd->arg1);
	fprintf(dst, "\tjal load_frame\n");
}

// generates code for mutiplication operations
void mips_mul(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tmul $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}


// generates code for division operations
void mips_div(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tdiv $t%i, $t%i\n", src_reg0, src_reg1);
	fprintf(dst, "\tmflo $t%i\n", dst_reg);
}

// generates code for modulo operations
void mips_mod(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tdiv $t%i, $t%i\n", src_reg0, src_reg1);
	fprintf(dst, "\tmfhi $t%i\n", dst_reg);
}

// generates labels in the code
void mips_label(quad *qd, FILE *dst) {
	fprintf(dst, "%s:\n", (qd)->result);
}

