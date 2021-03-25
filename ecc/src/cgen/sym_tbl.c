#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "sym_tbl.h"

extern int pc;

// Symbol nodes are the containers which make up the symbol table.
// These nodes work the same as buckets in a hash map 
typedef struct _symbol_node {
	symbol_t symbol;
	struct _symbol_node *next;
} symbol_node;

// symbol_table - The symbol table which holds all the symbols
// size			- The current number of elements in the symbol table
// capacity		- The current total number of buckets (symbol nodes) in the symbol table
symbol_node **symbol_table;
int size, capacity;

// given a string, produces a value which will determine which
// bucket within the symbol table the string will be placed.
int get_hash(char *token) {
	int total = 0;
	while (*token) {
		total += *token;
		token++;
	}
	return total % capacity;
}

// inserts new symbols with an associated value to the symbol table
// so their values may be retreived later during the assembly process
void insert_symbol(char *token, int type, int value) {
	// creates the symbol table if it doesn't already exist
	if (!symbol_table) {
		size = 0, 
		capacity = 8;
		symbol_table = calloc(capacity, sizeof(symbol_node*));
	}
	
	/* todo: probably want to resize the table occationally aswell */
	
	// determine which bucket to insert into and find the next 
	// empty node attatched to that bucket. if the bucket chosen
	// bucket has yet to exist, it is initialized and the new 
	// symbol is placed within it
	int index = get_hash(token);
	symbol_node *node;
	if (symbol_table[index]) {
		 node = symbol_table[index];
		 while (node->next) {
		 	node = node->next;
		 }
		 node->next = malloc(sizeof(symbol_node));
		 node = node->next;
	} else {
		symbol_table[index] = malloc(sizeof(symbol_node));
		node = symbol_table[index];	
	}
	node->symbol.identifer = calloc(strlen(token) + 1, sizeof(char));
	strcpy(node->symbol.identifer, token);
	node->symbol.type = type;
	node->symbol.value = value;
	node->next = 0;
	size += 1;
}

// retrieves the value asscoiated with then given symbol
// from the symbol table
symbol_t *get_symbol(char *token) {
	int index = get_hash(token);
	if (!symbol_table[index]) {
		return 0;
	}
	symbol_node *node = symbol_table[index];
	while (node) {
		if (!strcmp(node->symbol.identifer, token)) {
			return &(node->symbol);
		}
		node = node->next;
	}
	return 0;
}

