#ifndef TAC_H
#define TAC_H

int is_temp(char *token);

int is_label(char *token);

char* is_int(char *token);

int is_keyword(char *token);

int get_op(char *op);

#endif /* TAC_H */

