#ifndef SCOPE_CHAIN_H
#define SCOPE_CHAIN_H

// adds a new scope to the end of the scope chain
void link_scope(void *scope);

// removes the last scope which was added to the scope chain
void unlink_scope();

// returns the current scope at the end of the scope chain
void **this_scope();

// returns a scope which is one level above the given scope
// on the scope chain
void **prev_scope(void *chain);

void *global_scope; // the global scope
void *main_scope;   // the scope of the main function

#endif /* SCOPE_CHAIN_H */

