#ifndef TARGET_H
#define TARGET_H

#include <stdio.h>

#include "quad.h"

typedef void (*header_t)(FILE*, FILE*);
typedef void (*operation_t)(quad*, FILE*);
typedef void (*terminate_t)(FILE*);

typedef struct _target_t {
	header_t header;
	operation_t assign;
	operation_t add;
	operation_t sub;
	operation_t equal;
	operation_t greater_than_or_equal;
	operation_t greater_than;
	operation_t less_than_or_equal;
	operation_t less_than;
	operation_t not_equal;
	operation_t cond_jump;
	operation_t jump;
	operation_t print;
	operation_t label;
	terminate_t terminate;
} target_t;

#endif /* TARGET_H */ 

