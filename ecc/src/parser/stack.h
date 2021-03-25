#ifndef STACK_H
#define STACK_H

// a typical stack implementation

typedef struct _node {
	void *data;
	struct _node *prev;
} node_t;

typedef struct _stack {
	node_t *head;
} stack_t;

void push(stack_t **stackptr, void *data);

node_t *peek(stack_t **stackptr);

node_t *pop(stack_t **stackptr);

#endif /* STACK_H */
