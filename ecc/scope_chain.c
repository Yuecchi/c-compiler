#include <stdlib.h>
#include <stdio.h>

#include "scope_chain.h"

typedef struct _scope_chain_t {
	void *scope;
	struct _scope_chain_t *prev; 
} scope_chain_t;

scope_chain_t *scope_chain;

void link_scope(void *scope) {
	if (!scope_chain) {
		global_scope = scope;
		scope_chain = malloc(sizeof(scope_chain_t));
		scope_chain->scope = scope;
		scope_chain->prev  = 0;
		return;
	}
	scope_chain_t *prev = scope_chain;
	scope_chain = malloc(sizeof(scope_chain_t));
	scope_chain->scope = scope;
	scope_chain->prev  = prev;
}

void unlink_scope() {
	if (scope_chain) {
		scope_chain_t *old = scope_chain;
		scope_chain = old->prev;
		free(old);
	}	
}

void **this_scope() {
	return (void**)scope_chain;
}

void **prev_scope(void *chain) {
	return (void**)(((scope_chain_t*)chain)->prev); 
}
