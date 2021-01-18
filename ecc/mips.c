#include <string.h>

#include "mips.h"
#include "tac.h"

int get_val_reg(char *temp) {
	return (temp[strlen(temp) - 2] - '0') % 4;
}
int get_adr_reg(char *temp) {
	return 4 + get_val_reg(temp);
}

void mips_header(FILE *dst, FILE *src) {
	char buf[32];
	fprintf(dst, "\t.data\n");
	while (fgets(buf, sizeof buf, src)) {
		fprintf(dst, "%c:\t.word 0x0\n", *buf);
	}
	fprintf(dst, "\t.text\nmain:\n");	
}

void mips_assign(quad *qd, FILE *dst) {
	int val_reg, adr_reg;
	if (is_temp(qd->result)) {
		if (is_int(qd->arg1)) { /* _tn_ = INTEGER */
			val_reg = get_val_reg(qd->result);
			fprintf(dst, "\tli $t%i, %s\n", val_reg, qd->arg1); // load immediate
		} else { /* _tn_ = x */
			val_reg = get_val_reg(qd->result);
			adr_reg = get_adr_reg(qd->result);
			fprintf(dst, "\tla $t%i, %s\n", adr_reg, qd->arg1); // load address
			fprintf(dst, "\tlw $t%i, ($t%i)\n", val_reg, adr_reg); // load word
		}
	} else { /* x = _tn_ */
		val_reg = get_val_reg(qd->arg1);
		adr_reg = get_adr_reg(qd->arg1);
		fprintf(dst, "\tla $t%i, %s\n", adr_reg, qd->result); // load address
		fprintf(dst, "\tsw $t%i, ($t%i)\n", val_reg, adr_reg); // load word
	}
}

void mips_add(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tadd $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

void mips_sub(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsub $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

void mips_equal(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tseq $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);	
}

void mips_greater_than_or_equal(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsge $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

void mips_greater_than(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsgt $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

void mips_less_than_or_equal(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsle $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);
}

void mips_less_than(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tslt $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);	
}

void mips_not_equal(quad *qd, FILE *dst) {
	int dst_reg   = get_val_reg(qd->result);
	int src_reg0 = get_val_reg(qd->arg1);
	int src_reg1 = get_val_reg(qd->arg2);
	fprintf(dst, "\tsne $t%i, $t%i, $t%i\n", dst_reg, src_reg0, src_reg1);		
}

void mips_cond_jump(quad *qd, FILE *dst) {
	int val_reg = get_val_reg(qd->arg1);
	fprintf(dst, "\tbeqz $t%i, %s\n", val_reg, qd->result);
}

void mips_jump(quad *qd, FILE *dst) {
	fprintf(dst, "\tj %s\n", qd->arg1);
}

void mips_print(quad *qd, FILE *dst) {
	int val_reg = get_val_reg(qd->arg1);
	fprintf(dst, "\tmove $a0, $t%i\n", val_reg);
	fprintf(dst, "\tli $v0, 1\n");
	fprintf(dst, "\tsyscall\n");
}

void mips_label(quad *qd, FILE *dst) {
	fprintf(dst, "%s:\n", qd->result);
}

void mips_terminate(FILE *dst) {	
	fprintf(dst, "\tli $v0, 10\n");
	fprintf(dst, "\tsyscall\n");
}

