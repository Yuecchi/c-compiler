/*******************************************************************************
*
* RDP release 1.50 by Adrian Johnstone (A.Johnstone@rhbnc.ac.uk) 20 December 1997
*
* This file may be freely distributed. Please mail improvements to the author.
*
*******************************************************************************/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "textio.h"
#include "memalloc.h"
#include "ma_aux.h"

struct _label_stack_node {
	char *start;
	char *end;
	label_stack_node next;
};

struct _label_stack {
	label_stack_node head;
};

static long unsigned temp_count = 1; 
static long unsigned lab_count = 1; 

char * new_temp(void)
{
  char * ret =(char *) mem_malloc(30); 
  
  sprintf(ret, "_t%lu_", temp_count++); 
  
  return ret; 
}


char * new_lab(void)
{
  char * ret =(char *) mem_malloc(30); 
  
  sprintf(ret, "_L%lu_", lab_count++); 
  
  return ret; 
}

label_stack create_label_stack() {
	label_stack lstack;
	
	lstack = malloc(sizeof(*lstack));
	lstack->head = NULL;
	
	return lstack;
}

void push(label_stack lstack, char *start, char *end) {
	if (!lstack->head) {
		lstack->head = malloc(sizeof(label_stack_node));	
		lstack->head->start = start;
		lstack->head->end = end;
		lstack->head->next = NULL;
		return;
	}
	label_stack_node temp = malloc(sizeof(label_stack_node));
	temp->start = start;
	temp->end = end;
	temp->next = lstack->head;
	lstack->head = temp;
}

void *pop(label_stack lstack) {
	if (!lstack->head) {
		return NULL;
	}
	
	label_stack_node temp = lstack->head;
	lstack->head = temp->next;
	free(temp);
	
	return temp;	
}

char *start(label_stack lstack) {
		if (!lstack->head) {
		return NULL;
	}
	return lstack->head->start;
}

char *end(label_stack lstack) {
		if (!lstack->head) {
		return NULL;
	}
	return lstack->head->end;
}

/* End of ma_aux.c */
