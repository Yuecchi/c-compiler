#ifndef MIPS_H
#define MIPS_H

#include <stdio.h>

#include "target.h"
#include "quad.h"

// Generates the header for mips programs. The header includes 
// global variables from the source program and a pair of runtime
// functions which assist with the operation of functions
void mips_header(FILE *dst, FILE *src);

// generates code for assignment operations
void mips_assign(quad *qd, FILE *dst);

// generates code for addition operations
void mips_add(quad *qd, FILE *dst);

// generates code for subtraction operations
void mips_sub(quad *qd, FILE *dst);

// generates code for is equal operations
void mips_equal(quad *qd, FILE *dst);

// generates code for great than or equal to operations
void mips_greater_than_or_equal(quad *qd, FILE *dst);

// generates code for greater than operations
void mips_greater_than(quad *qd, FILE *dst);

// generates code for less than or equal to operations
void mips_less_than(quad *qd, FILE *dst);

// generates code for less then operations
void mips_less_than_or_equal(quad *qd, FILE *dst);

// generates code fornot equal operations
void mips_not_equal(quad *qd, FILE *dst);

// generates code for conditional jumps
void mips_cond_jump(quad *qd, FILE *dst);

// generates code for undconditional jumps
void mips_jump(quad *qd, FILE *dst);

// generates code from print operations
// all prints include an implcit trailing newline
void mips_print(quad *qd, FILE *dst);

// generates code for program termination
void mips_terminate(quad *qd, FILE *dst);

// generates code for function returns
void mips_return(quad *qd, FILE *dst);

// generates code that affects the stack
void mips_push(quad *qd, FILE *dst);

// generates code to perform function calls
void mips_call(quad *qd, FILE *dst);

// generates code for mutiplication operations
void mips_mul(quad *qd, FILE *dst);

// generates code for division operations
void mips_div(quad *qd, FILE *dst);

// generates code for modulo operations
void mips_mod(quad *qd, FILE *dst);

// generates labels in the codes
void mips_label(quad *qd, FILE *dst);

// the target for the mips architecture. This contains the 
// set of functions required to generate mips programs
static const target_t mips = {
	mips_header,
	mips_assign,
	mips_add,
	mips_sub,
	mips_equal,
	mips_greater_than_or_equal,
	mips_greater_than,
	mips_less_than_or_equal,
	mips_less_than,
	mips_not_equal,
	mips_cond_jump,
	mips_jump,
	mips_print,
	mips_terminate,
	mips_return,
	mips_push,
	mips_call,
	mips_mul,
	mips_div,
	mips_mod,
	mips_label
};

#endif /* MIPS_H */

