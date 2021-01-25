#ifndef SCOPE_CHAIN_H
#define SCOPE_CHAIN_H

void link_scope(void *scope);

void unlink_scope();

void **this_scope();

void **prev_scope(void *chain);

void *global_scope;
void *main_scope;

#endif /* SCOPE_CHAIN_H */

