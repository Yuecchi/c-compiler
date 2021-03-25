#ifndef SYM_TBL_H
#define SYM_TBL_H

// Symbols contain key information about global variables / arrays and functions
// from the source program

// identifer - An identifer for either a varaible, array or function
// type 	 - The data type of the symbol, can be one of either VAR, ARR, or FUNC (see type.h)
// value 	 - A value associated with the symbol which represents something
//             different depending on the symbol's type
//
//             VAR   - The value assigned to the variable
//             ARR   - The size of the array
//             FUNC  - the number of bytes required to store the function's local variables
//
typedef struct _symbol {
	char *identifer; 
	int type;		 
	int value;		 	               
} symbol_t;


// inserts new symbols with an associated value to the symbol table
// so their values may be retreived later during the assembly process
void insert_symbol(char *token, int type, int value); 

// retrieves the value asscoiated with then given symbol
// from the symbol table
symbol_t *get_symbol(char *token);

#endif /* SYM_TBL_H */
