#ifndef QUAD_H
#define QUAD_H

typedef struct _quad {
	char *op;
	char *arg1;
	char *arg2;
	char *result;
} quad;

char *quad_fill(quad *qd, char* pch);  

void quad_print(quad *qd);

#endif /* QUAD_H */

