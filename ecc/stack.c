#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

void push(stack_t **stackptr, void *data) {
	if (!(*stackptr)) {
		*stackptr = malloc(sizeof(stack_t));
		(*stackptr)->head = malloc(sizeof(node_t));
		(*stackptr)->head->data = data;
		(*stackptr)->head->prev = 0;
		return;
	}
	stack_t *stack = *stackptr;
	node_t *prev = stack->head;
	stack->head = malloc(sizeof(node_t));
	stack->head->data = data;
	stack->head->prev = prev;
}

node_t *peek(stack_t **stackptr) {
	if (*stackptr) {
		return (*stackptr)->head;	
	}
	return 0;
}

node_t *pop(stack_t **stackptr) {
	if (*stackptr) {
		stack_t *stack = *stackptr;
		if (stack->head) {
			node_t *old = stack->head;
			stack->head = stack->head->prev;
			return old;
		}
		return 0;
	}
	return 0;
}

