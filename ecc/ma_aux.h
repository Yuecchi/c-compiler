/****************************************************************************
*
* RDP release 1.50 by Adrian Johnstone (A.Johnstone@rhbnc.ac.uk) 20 December 1997
*
* This file may be freely distributed. Please mail improvements to the author.
*
****************************************************************************/

typedef struct _label_stack_node *label_stack_node;
typedef struct _label_stack *label_stack;

FILE * fp;
label_stack loop_stack;

char * new_temp(void); 
char * new_lab(void);

label_stack create_label_stack();
void push(label_stack lstack, char *start, char *end);
void *pop(label_stack lstack);
char *start(label_stack lstack);
char *end(label_stack lstack);

/* End of ma_aux.h */
