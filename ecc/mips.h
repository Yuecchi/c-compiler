#ifndef MIPS_H
#define MIPS_H

#include <stdio.h>

#include "target.h"
#include "quad.h"

void mips_header(FILE *dst, FILE *src);

void mips_assign(quad *qd, FILE *dst);

void mips_add(quad *qd, FILE *dst);

void mips_sub(quad *qd, FILE *dst);

void mips_equal(quad *qd, FILE *dst);

void mips_greater_than_or_equal(quad *qd, FILE *dst);

void mips_greater_than(quad *qd, FILE *dst);

void mips_less_than(quad *qd, FILE *dst);

void mips_less_than_or_equal(quad *qd, FILE *dst);

void mips_not_equal(quad *qd, FILE *dst);

void mips_cond_jump(quad *qd, FILE *dst);

void mips_jump(quad *qd, FILE *dst);

void mips_print(quad *qd, FILE *dst);

void mips_terminate(quad *qd, FILE *dst);

void mips_return(quad *qd, FILE *dst);

void mips_push(quad *qd, FILE *dst);

void mips_call(quad *qd, FILE *dst);

void mips_label(quad *qd, FILE *dst);

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
	mips_label
};

#endif /* MIPS_H */

