/****************************************************************************
*
* RDP release 1.50 by Adrian Johnstone (A.Johnstone@rhbnc.ac.uk) 20 December 1997
*
* This file may be freely distributed. Please mail improvements to the author.
*
****************************************************************************/
#include <stdio.h>

#include "stack.h"

FILE * fp;
stack_t *loop_stack;

char * new_temp(void); 
char * new_lab(void);

/* End of ma_aux.h */
