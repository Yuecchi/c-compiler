#include <stdlib.h>
#include <stdio.h>

#include "scope_chain.h"

// my external scope chain implementation which is effectively
// a linked list
typedef struct _scope_chain_t {
	void *scope;
	struct _scope_chain_t *prev; 
} scope_chain_t;

// the scope chain used during the parse
scope_chain_t *scope_chain; 

// adds a new scope to the end of the scope chain
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

// removes the last scope which was added to the scope chain
void unlink_scope() {
	if (scope_chain) {
		scope_chain_t *old = scope_chain;
		scope_chain = old->prev;
		free(old);
	}	
}

// returns the current scope at the end of the scope chain
void **this_scope() {
	return (void**)scope_chain;
}

// returns a scope which is one level above the given scope
// on the scope chain
void **prev_scope(void *chain) {
	return (void**)(((scope_chain_t*)chain)->prev); 
}
