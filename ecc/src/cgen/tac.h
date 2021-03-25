#ifndef TAC_H
#define TAC_H

// determines whether or not a token is a temporary variable
int is_temp(char *token);

// determines whether or not a token is a local variable
int is_fp(char *token);

// determines whether or not a token is a label
int is_label(char *token);

// determines whether or not a token is an integer
char* is_int(char *token);

// determines whether or not a token is a keyword
int is_keyword(char *token);

// returns the ordinal value associated with an operation
int get_op(char *op);

#endif /* TAC_H */

