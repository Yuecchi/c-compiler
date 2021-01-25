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

static long unsigned temp_count = 1; 
static long unsigned lab_count = 1; 

char * new_temp(void)
{
  char * ret =(char *) mem_malloc(30); 
  
  sprintf(ret, "$t%lu", temp_count++); 
  
  return ret; 
}

char * new_lab(void)
{
  char * ret =(char *) mem_malloc(30); 
  
  sprintf(ret, "#L%lu", lab_count++); 
  
  return ret; 
}

/* End of ma_aux.c */
