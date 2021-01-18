#include <string.h>

#include "tac.h"

#define INTEGERS "0123456789" 

const char *KEYWORDS[] = {
	"if",	 // 1
	"goto",	 // 2
	"print", // 3
	NULL
};

const char *OP[] = {
	"=", 	 // 1
	"+", 	 // 2
	"-", 	 // 3
	"==",    // 4
	">=",	 // 5
	">", 	 // 6
	"<=",	 // 7
	"<",     // 8
	"!=",    // 9
	"if", 	 // 10
	"goto",  // 11
	"print", // 12
	NULL
};

int is_temp(char *token) {
	return token[0] == '_' && token[1] == 't';
}

int is_label(char *token) {
	return token[0] == '_' && token[1] == 'L';
}

char* is_int(char *token) {
	return strchr(INTEGERS, *token);
}

int is_keyword(char *token) {
	for (int i = 0; KEYWORDS[i]; i++) {
		if (!strcmp(token, KEYWORDS[i])) {
			return i + 1;
		}
	}
	return 0;
}

int get_op(char *op) {
	for (int i = 0; OP[i]; i += 1) {
		if (!strcmp(op, OP[i])) {
			return i + 1;
		}		
	}
	return 0;
}

