#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "quad.h"
#include "tac.h"
#include "target.h"
#include "mips.h"
#include "sym_tbl.h"

int main() {	
	
	quad qd;
	char src_buf[32];
	target_t target = mips;
	
	FILE *dst     = fopen("func.a", "w");
	FILE *tbl_src = fopen("func.tbl", "r");
	if (!(tbl_src && dst)) {
		return 1; // file io error
	}
	
	// read .tbl file into symbol table
	while(fgets(src_buf, sizeof(src_buf), tbl_src)) {
		char *identifer = strtok(src_buf, " ");
		int type        = atoi(strtok(NULL, " "));
		int value       = atoi(strtok(NULL, " "));
		insert_symbol(identifer, type, value);
	}
	
	rewind(tbl_src);
	// generate the program header
	target.header(dst, tbl_src);
	fclose(tbl_src);
	
	FILE *tac_src = fopen("func.tac", "r");
	if (!tac_src) {
		return 1; // file io error
	}	
	
	// Main loop of the code generator. Read each line of the 
	// three-address code file to package them into quads. The 
	// operation in each quad is used to executed an associated
	// function of the target architecture in order to generate
	// code relevant to that operation and the rest of the contents
	// of the quad. 
	while(fgets(src_buf, sizeof(src_buf), tac_src)) {
		src_buf[strlen(src_buf) - 1] = '\0';
		quad_fill(&qd, src_buf);
		// quad_print(&qd);
		if (qd.op) {
			int op = get_op(qd.op);
			((operation_t)((target_t**)&target)[op])(&qd, dst);
		} else {
			target.label(&qd, dst);
		}
	}
	
	fclose(tac_src);
	fclose(dst);
	
	return 0;
}

