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

// determines whether or not a token is an array element
int is_array(char *token) {
	return token[strlen(token) - 1] == ']';
}

// if a token is found to be an array element, this function is 
// used to isolate the index value which will be used to locate
// the elements location in memory
void isolate_index(quad *qd, char *target) {
	char *left  = strchr(target, '[');
	char *right = strchr(target, ']');
	*right = '\0';
	qd->arg2 = left + 1;
	*left = '\0';
}

// parses a line of three-address code and packages
// the instruction into a quad 
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
			
			/* x[n] OR $fp(n)[m] = ??? */
			if (is_array(qd->result)) {
				isolate_index(qd, qd->result);
			}
			
			/* _tn_ = x[n] OR $fp(n)[m] */
			if (is_array(qd->arg1)) {
				isolate_index(qd, qd->arg1);
			}		
					
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

// debug function for printing the contents of quads
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

