#include <stdio.h>
#include <string.h>

#include "quad.h"
#include "tac.h"
#include "target.h"
#include "mips.h"

int main() {	
	
	quad qd;
	char src_buf[32];
	target_t target = mips;
	
	FILE *dst     = fopen("eac.a", "w");
	FILE *tbl_src = fopen("eac.tbl", "r");
	if (!(tbl_src && dst)) {
		return 1; // file io error
	}
	target.header(dst, tbl_src);
	fclose(tbl_src);
	
	FILE *tac_src = fopen("eac.tac", "r");
	if (!tac_src) {
		return 1; // file io error
	}	
	
	while(fgets(src_buf, sizeof src_buf, tac_src)) {
		src_buf[strlen(src_buf) - 1] = '\0';
		quad_fill(&qd, src_buf);
		if (qd.op) {
			int op = get_op(qd.op);
			((operation_t)((target_t**)&target)[op])(&qd, dst);
		} else {
			target.label(&qd, dst);
		}
	}
	target.terminate(dst);
	
	fclose(tac_src);
	fclose(dst);
	
	return 0;
}

