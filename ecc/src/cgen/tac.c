#include <string.h>

#include "tac.h"

#define INTEGERS "0123456789" 


// contaisn the set of possible keywords that can appear 
// in a three-address code file
const char *KEYWORDS[] = {
	"if",	 	 // 1
	"goto",	 	 // 2
	"print", 	 // 3
	"terminate", // 4
	"return",	 // 5
	"push",		 // 6
	"call",		 // 7
	NULL
};

// contains the set of possible operations that can appear
// in a three-address code file. The values to the right 
// are the ordinal values associated with each operation.
// These values are used to locate the function in the 
// chosen target architecture which generates the code for
// the associated operation
const char *OP[] = {
	"=", 	 	 // 1
	"+", 	 	 // 2
	"-", 	 	 // 3
	"==",    	 // 4
	">=",	 	 // 5
	">", 	 	 // 6
	"<=",	 	 // 7
	"<",     	 // 8
	"!=",    	 // 9
	"if", 	 	 // 10
	"goto",  	 // 11
	"print", 	 // 12
	"terminate", // 13
	"return",	 // 14
	"push",		 // 15
	"call",		 // 16
	"*",         // 17
	"/",         // 18
	"%",         // 19
	NULL
};

// determines whether or not a token is a temporary variable
int is_temp(char *token) {
	return token[0] == '$' && token[1] == 't';
}

// determines whether or not a token is a local variable
int is_fp(char *token) {
	return token[0] == '$' && token[1] == 'f';
}

// determines whether or not a token is a label
int is_label(char *token) {
	return token[0] == '#';
}

// determines whether or not a token is an integer
char* is_int(char *token) {
	return strchr(INTEGERS, *token);
}

// determines whether or not a token is a keyword
int is_keyword(char *token) {
	for (int i = 0; KEYWORDS[i]; i++) {
		if (!strcmp(token, KEYWORDS[i])) {
			return i + 1;
		}
	}
	return 0;
}

// returns the ordinal value associated with an operation
int get_op(char *op) {
	for (int i = 0; OP[i]; i += 1) {
		if (!strcmp(op, OP[i])) {
			return i + 1;
		}		
	}
	return 0;
}

