#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INTEGERS "0123456789" 

FILE *tac_src;
FILE *tbl_src;
FILE *asm_src;

char src_buf[32];
char *pch;
char *opr1, opr2;

bool is_temp(char* tmp) {
	return tmp[0] == '_' && tmp[1] == 't';
}

bool is_label(char* tmp) {
	return tmp[0] == '_' && tmp[1] == 'L';
}

char* is_int(char* tmp) {
	return strchr(INTEGERS, *tmp);
}

int main() {
	
	asm_src = fopen("eac.a", "w");
	
	/* read from symbol table and generate .data segment of mips code */ 
	tbl_src = fopen("eac.tbl", "r");
	fprintf(asm_src, "\t.data\n");
	while (fgets(src_buf, sizeof src_buf, tbl_src)) {
		fprintf(asm_src, "%c:\t.word 0x0\n", *src_buf);
	}
	fclose(tbl_src);
	
	/* read from the intermdiate code file and generate the mips program */
	tac_src = fopen("eac.tac", "r");
	fprintf(asm_src, "\t.text\nmain:\n");
	while (fgets(src_buf, sizeof src_buf, tac_src)) {
		src_buf[strlen(src_buf) - 1] = '\0';
		pch = strtok(src_buf, " \t");
		while (pch) {
			// either _tn_ or ID or _Ln_ or if
			if (is_temp(pch)) { // _tn__
				pch = strtok(NULL, " \t");
				if (*pch == '=') {
					pch = strtok(NULL, " \t");
					if (is_int(pch)) {
						// TEMP = INTEGER_LITERAL
						fprintf(asm_src, "\tli $t0, %s\n", pch);
					} else if (is_temp(pch)) {
						pch = strtok(NULL, " \t");
						if (*pch == '+') {
							pch = strtok(NULL, " \t");
							if (is_int(pch)) {
								// TEMP = TEMP + INTEGER_LITERAL
								fprintf(asm_src, "\taddi $t0, $t0, %s\n", pch);																
							} else {
								// TEMP = TEMP + IDENTIFER
								fprintf(asm_src, "\tla $t2, %s\n", pch);
								fprintf(asm_src, "\tlw $t1, ($t2)\n");
								fprintf(asm_src, "\tadd $t0, $t0, $t1\n");
							}
						} else if (*pch == '-') {
							pch = strtok(NULL, " \t");
							if (is_int(pch)) {
								// TEMP = TEMP + INTEGER_LITERAL
								fprintf(asm_src, "\taddi $t0, $t0, -%s\n", pch);																
							} else {
								// TEMP = TEMP + IDENTIFER
								fprintf(asm_src, "\tla $t2, %s\n", pch);
								fprintf(asm_src, "\tlw $t1, ($t2)\n");
								fprintf(asm_src, "\tsub $t0, $t0, $t1\n");
							}
						}
					} else {
						// TEMP = IDENTIFER
						fprintf(asm_src, "\tla $t1, %s\n", pch);
						fprintf(asm_src, "\tlw $t0, ($t1)\n");
					}
				}
			} else if (is_label(pch)) { // _Ln_
				fprintf(asm_src, "%s:\n", pch);
			} else if (!strcmp("if", pch)) { // if
				for (int i = 0; i < 5; i ++) {
					pch = strtok(NULL, " \t");
				}
				fprintf(asm_src, "\tbeqz $t0, %s\n", pch);
			} else if (!strcmp("goto", pch)) {
				pch = strtok(NULL, " \t");
				fprintf(asm_src, "\tj %s\n", pch);
			} else if (!strcmp("print", pch)) {
				pch = strtok(NULL, " \t");
				fprintf(asm_src, "\tmove $a0, $t0\n");
				fprintf(asm_src, "\tli $v0, 1\n");
				fprintf(asm_src, "\tsyscall\n");
			} else { // ID
				// IDENTIFER = TEMP
				fprintf(asm_src, "\tla $t1, %s\n", pch);
				fprintf(asm_src, "\tsw $t0, ($t1)\n");
				pch = strtok(NULL, " \t");
				pch = strtok(NULL, " \t");
			}
			pch = strtok(NULL, " \t");
		}
	}
	fclose(tac_src);
	
	/* generate code to terminate program */	
	fprintf(asm_src, "\tli $v0, 10\n");
	fprintf(asm_src, "\tsyscall\n");		
	fclose(asm_src);
	
	return 0;
}
