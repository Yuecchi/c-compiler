#ifndef QUAD_H
#define QUAD_H

// A quad represents a three-address code instruction
//
// op     - the operation the TAC instruction intends to be performed
// arg1   - the first operand of the operation
// arg2   - the second operand of the operation
// result - the target location of the operations result. This can either be
//          a location where the result will be stored, or a location the 
//          program will jump to
typedef struct _quad {
	char *op;
	char *arg1;
	char *arg2;
	char *result;
} quad;

// parses a line of three-address code and packages
// the instruction into a quad 
char *quad_fill(quad *qd, char* pch);  

// debug function for printing the contents of quads
void quad_print(quad *qd);

#endif /* QUAD_H */

