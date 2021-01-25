#ifndef SYM_TBL_H
#define SYM_TBL_H

typedef struct _symbol {
	char *identifer;
	int type;
	int value;
} symbol_t;

void insert_symbol(char *token, int type, int value); 

symbol_t *get_symbol(char *token);

#endif /* SYM_TBL_H */
