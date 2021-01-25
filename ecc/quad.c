#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "quad.h"
#include "tac.h"

/*
 * op
 * +     (result = arg1 op arg2)
 * -     (result = arg1 op arg2)
 * =     (result op arg1)
 * >     (result = arg1 op arg2)
 * if    (op arg1 == 0 goto result)
 * goto  (op arg1)
 * print (op arg1) 
 *
 */

const int QUAD_SIZE = sizeof(quad) / sizeof(char*);

char* quad_fill(quad *qd, char *str) {
	memset(qd, 0, sizeof(*qd));
	char *pch = strtok(str, " \t");
	if (is_label(pch)) { /* label */
			qd->op = NULL;
			qd->result = pch + 1;
	} else {		
		int keyword = is_keyword(pch);
		if (!keyword) {
			/* result op arg1 (assignment) */
			qd->result = pch;
			qd->op     = strtok(NULL, " \t");
			qd->arg1   = strtok(NULL, " \t");
			
			/* _tn_ = call func */
			if (!strcmp(qd->arg1, "call")) {
				qd->arg2 = strtok(NULL, " \t");
				return qd->op; 
			}

			/* result = arg1 op arg2 (binary assignment) */
			char *pch = strtok(NULL, " \t");
			if (pch) {
				qd->op   = pch;
				qd->arg2 = strtok(NULL, " \t"); 
			}
		} else {
			/* unconditional jump / print statment / terminate / return */
			qd->op = pch;
			qd->arg1 = strtok(NULL, " \t");
			switch (keyword) {
				case 1: /* conditional jump */
					for (int i = 0; i < 4; i++) {
						pch = strtok(NULL, " \t");
					}
					qd->result = pch;
					break;
				case 6: /* push */
					qd->arg2 = strtok(NULL, " \t");
					break;
				default:
					return NULL;
			}
		}
	}
	return qd->op;
}

void quad_print(quad *qd) {
	for (int i = 0;i < QUAD_SIZE; i += 1) {
		char *tok = ((char**)qd)[i];
		if (tok) {
			printf("%s ", tok);
		} else {
			continue;
		}
	}
	printf("\n");
}

