/*******************************************************************************
*
* Parser generated by RDP on Jan 19 2021 13:08:30 from eac.bnf
*
*******************************************************************************/
#include <time.h>
#include "arg.h"
#include "graph.h"
#include "memalloc.h"
#include "scan.h"
#include "set.h"
#include "symbol.h"
#include "textio.h"
#include "stdlib.h"
#include "ma_aux.h"
#include "tbl_aux.h"
#include ".h"

char
 *rdp_sourcefilename = NULL,   /* source file name */
 *rdp_outputfilename = "eac.out";         /* output file name */

int
  rdp_symbol_echo = 0,                 /* symbol echo flag */
  rdp_verbose = 0,                     /* verbosity flag */
  rdp_pass;                            /* pass number */

int rdp_error_return = 0;              /* return value for main routine */

char *rdp_tokens = "IGNORE\0" 
"ID\0" "INTEGER\0" "REAL\0" "CHAR\0" "CHAR_ESC\0" "STRING\0" "STRING_ESC\0" "COMMENT\0" 
"COMMENT_VISIBLE\0" "COMMENT_NEST\0" "COMMENT_NEST_VISIBLE\0" "COMMENT_LINE\0" "COMMENT_LINE_VISIBLE\0" "EOF\0" "EOLN\0" "'!'\0" 
"'!='\0" "'('\0" "')'\0" "'+'\0" "'-'\0" "';'\0" "'<'\0" "'<='\0" 
"'='\0" "'=='\0" "'>'\0" "'>='\0" "'break'\0" "'continue'\0" "'elif'\0" "'else'\0" 
"'if'\0" "'int'\0" "'print'\0" "'while'\0" "'{'\0" "'}'\0" ;

global_data * global_temp = NULL;
void* global = NULL;

/* Load keywords */
static void rdp_load_keywords(void)
{
  scan_load_keyword("!", NULL, RDP_T_16 /* ! */, SCAN_P_IGNORE);
  scan_load_keyword("!=", NULL, RDP_T_17 /* != */, SCAN_P_IGNORE);
  scan_load_keyword("(", NULL, RDP_T_18 /* ( */, SCAN_P_IGNORE);
  scan_load_keyword(")", NULL, RDP_T_19 /* ) */, SCAN_P_IGNORE);
  scan_load_keyword("+", NULL, RDP_T_20 /* + */, SCAN_P_IGNORE);
  scan_load_keyword("-", NULL, RDP_T_21 /* - */, SCAN_P_IGNORE);
  scan_load_keyword(";", NULL, RDP_T_22 /* ; */, SCAN_P_IGNORE);
  scan_load_keyword("<", NULL, RDP_T_23 /* < */, SCAN_P_IGNORE);
  scan_load_keyword("<=", NULL, RDP_T_24 /* <= */, SCAN_P_IGNORE);
  scan_load_keyword("=", NULL, RDP_T_25 /* = */, SCAN_P_IGNORE);
  scan_load_keyword("==", NULL, RDP_T_26 /* == */, SCAN_P_IGNORE);
  scan_load_keyword(">", NULL, RDP_T_27 /* > */, SCAN_P_IGNORE);
  scan_load_keyword(">=", NULL, RDP_T_28 /* >= */, SCAN_P_IGNORE);
  scan_load_keyword("break", NULL, RDP_T_break, SCAN_P_IGNORE);
  scan_load_keyword("continue", NULL, RDP_T_continue, SCAN_P_IGNORE);
  scan_load_keyword("elif", NULL, RDP_T_elif, SCAN_P_IGNORE);
  scan_load_keyword("else", NULL, RDP_T_else, SCAN_P_IGNORE);
  scan_load_keyword("if", NULL, RDP_T_if, SCAN_P_IGNORE);
  scan_load_keyword("int", NULL, RDP_T_int, SCAN_P_IGNORE);
  scan_load_keyword("print", NULL, RDP_T_print, SCAN_P_IGNORE);
  scan_load_keyword("while", NULL, RDP_T_while, SCAN_P_IGNORE);
  scan_load_keyword("{", NULL, RDP_T_37 /* { */, SCAN_P_IGNORE);
  scan_load_keyword("}", NULL, RDP_T_38 /* } */, SCAN_P_IGNORE);
}

/* Set declarations */

  set_ ASSIGN_stop = SET_NULL;
  set_ BOOL_first = SET_NULL;
  set_ BOOL_stop = SET_NULL;
  set_ BREAK_stop = SET_NULL;
  set_ COMP_STMT_first = SET_NULL;
  set_ COMP_STMT_stop = SET_NULL;
  set_ COND_stop = SET_NULL;
  set_ CONTINUE_stop = SET_NULL;
  set_ DECL_stop = SET_NULL;
  set_ EXPR_first = SET_NULL;
  set_ EXPR_stop = SET_NULL;
  set_ JUMP_STMT_first = SET_NULL;
  set_ JUMP_STMT_stop = SET_NULL;
  set_ LOOP_stop = SET_NULL;
  set_ PRIMITIVE_first = SET_NULL;
  set_ PRIMITIVE_stop = SET_NULL;
  set_ PRINT_stop = SET_NULL;
  set_ STMT_first = SET_NULL;
  set_ STMT_stop = SET_NULL;
  set_ SUM_first = SET_NULL;
  set_ SUM_stop = SET_NULL;
  set_ TRNS_UNIT_first = SET_NULL;
  set_ TRNS_UNIT_stop = SET_NULL;
  set_ UNARY_first = SET_NULL;
  set_ UNARY_stop = SET_NULL;
  set_ rdp_BOOL_6_first = SET_NULL;
  set_ rdp_BOOL_7_first = SET_NULL;
  set_ rdp_COMP_STMT_0_first = SET_NULL;
  set_ rdp_COMP_STMT_1_first = SET_NULL;
  set_ rdp_COMP_STMT_2_first = SET_NULL;
  set_ rdp_EXPR_0_first = SET_NULL;
  set_ rdp_STMT_2_first = SET_NULL;
  set_ rdp_STMT_3_first = SET_NULL;
  set_ rdp_STMT_4_first = SET_NULL;
  set_ rdp_SUM_2_first = SET_NULL;
  set_ rdp_SUM_3_first = SET_NULL;
  set_ rdp_TRNS_UNIT_1_first = SET_NULL;
  set_ rdp_TRNS_UNIT_2_first = SET_NULL;
  set_ rdp_TRNS_UNIT_3_first = SET_NULL;
  set_ rdp_UNARY_0_first = SET_NULL;

/* Initialise sets */

static void rdp_set_initialise(void)
{
  set_assign_list(&ASSIGN_stop, SCAN_P_EOF, RDP_T_22 /* ; */,SET_END);
  set_assign_list(&BOOL_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&BOOL_stop, SCAN_P_EOF, RDP_T_19 /* ) */, RDP_T_22 /* ; */,SET_END);
  set_assign_list(&BREAK_stop, SCAN_P_EOF, RDP_T_22 /* ; */,SET_END);
  set_assign_list(&COMP_STMT_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_print, RDP_T_while, SET_END);
  set_assign_list(&COMP_STMT_stop, SCAN_P_EOF, RDP_T_38 /* } */,SET_END);
  set_assign_list(&COND_stop, SCAN_P_ID, SCAN_P_EOF, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_int, RDP_T_print, 
RDP_T_while, RDP_T_38 /* } */,SET_END);
  set_assign_list(&CONTINUE_stop, SCAN_P_EOF, RDP_T_22 /* ; */,SET_END);
  set_assign_list(&DECL_stop, SCAN_P_ID, SCAN_P_EOF, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_int, RDP_T_print, 
RDP_T_while,SET_END);
  set_assign_list(&EXPR_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&EXPR_stop, SCAN_P_EOF, RDP_T_19 /* ) */, RDP_T_22 /* ; */,SET_END);
  set_assign_list(&JUMP_STMT_first, RDP_T_break, RDP_T_continue, SET_END);
  set_assign_list(&JUMP_STMT_stop, SCAN_P_EOF, RDP_T_22 /* ; */,SET_END);
  set_assign_list(&LOOP_stop, SCAN_P_ID, SCAN_P_EOF, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_int, RDP_T_print, 
RDP_T_while, RDP_T_38 /* } */,SET_END);
  set_assign_list(&PRIMITIVE_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&PRIMITIVE_stop, SCAN_P_EOF, RDP_T_17 /* != */, RDP_T_19 /* ) */, RDP_T_20 /* + */, RDP_T_21 /* - */, 
RDP_T_22 /* ; */, RDP_T_23 /* < */, RDP_T_24 /* <= */, RDP_T_26 /* == */, RDP_T_27 /* > */, 
RDP_T_28 /* >= */,SET_END);
  set_assign_list(&PRINT_stop, SCAN_P_EOF, RDP_T_22 /* ; */,SET_END);
  set_assign_list(&STMT_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_print, RDP_T_while, SET_END);
  set_assign_list(&STMT_stop, SCAN_P_ID, SCAN_P_EOF, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_int, RDP_T_print, 
RDP_T_while, RDP_T_38 /* } */,SET_END);
  set_assign_list(&SUM_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&SUM_stop, SCAN_P_EOF, RDP_T_17 /* != */, RDP_T_19 /* ) */, RDP_T_22 /* ; */, RDP_T_23 /* < */, 
RDP_T_24 /* <= */, RDP_T_26 /* == */, RDP_T_27 /* > */, RDP_T_28 /* >= */,SET_END);
  set_assign_list(&TRNS_UNIT_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_int, RDP_T_print, RDP_T_while, SET_END);
  set_assign_list(&TRNS_UNIT_stop, SCAN_P_EOF,SET_END);
  set_assign_list(&UNARY_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&UNARY_stop, SCAN_P_EOF, RDP_T_17 /* != */, RDP_T_19 /* ) */, RDP_T_20 /* + */, RDP_T_21 /* - */, 
RDP_T_22 /* ; */, RDP_T_23 /* < */, RDP_T_24 /* <= */, RDP_T_26 /* == */, RDP_T_27 /* > */, 
RDP_T_28 /* >= */,SET_END);
  set_assign_list(&rdp_BOOL_6_first, RDP_T_17 /* != */, RDP_T_23 /* < */, RDP_T_24 /* <= */, RDP_T_26 /* == */, RDP_T_27 /* > */, 
RDP_T_28 /* >= */, SET_END);
  set_assign_list(&rdp_BOOL_7_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&rdp_COMP_STMT_0_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_print, RDP_T_while, SET_END);
  set_assign_list(&rdp_COMP_STMT_1_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_print, RDP_T_while, SET_END);
  set_assign_list(&rdp_COMP_STMT_2_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_print, RDP_T_while, SET_END);
  set_assign_list(&rdp_EXPR_0_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&rdp_STMT_2_first, RDP_T_break, RDP_T_continue, SET_END);
  set_assign_list(&rdp_STMT_3_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_print, SET_END);
  set_assign_list(&rdp_STMT_4_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_print, SET_END);
  set_assign_list(&rdp_SUM_2_first, RDP_T_20 /* + */, RDP_T_21 /* - */, SET_END);
  set_assign_list(&rdp_SUM_3_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&rdp_TRNS_UNIT_1_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_print, RDP_T_while, SET_END);
  set_assign_list(&rdp_TRNS_UNIT_2_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_int, RDP_T_print, RDP_T_while, SET_END);
  set_assign_list(&rdp_TRNS_UNIT_3_first, SCAN_P_ID, RDP_T_break, RDP_T_continue, RDP_T_if, RDP_T_int, RDP_T_print, RDP_T_while, SET_END);
  set_assign_list(&rdp_UNARY_0_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
}

/* Parser forward declarations and macros */
static void ASSIGN(void);
static char* BOOL(void);
static void BREAK(void);
static void COMP_STMT(void);
static void COND(void);
static void CONTINUE(void);
static void DECL(void);
static char* EXPR(void);
static void JUMP_STMT(void);
static void LOOP(void);
static char* PRIMITIVE(void);
static void PRINT(void);
static void STMT(void);
static char* SUM(void);
void TRNS_UNIT(void);
static char* UNARY(void);

/* Parser functions */
static void ASSIGN(void)
{
  char* name;
  char* val;
  {
    scan_test(NULL, SCAN_P_ID, &ASSIGN_stop);
    name = SCAN_CAST->id;
    scan_();
     if (!symbol_lookup_key(global, &name, NULL)) { \
                          text_message(TEXT_ERROR, "'%s' undeclared\n", name); \
                      } \
                   
    if (scan_test(NULL, RDP_T_25 /* = */, NULL))
    { /* Start of rdp_ASSIGN_1 */
      while (1)
      {
        {
          scan_test(NULL, RDP_T_25 /* = */, &ASSIGN_stop);
          scan_();
          val = EXPR();
           fprintf(fp, "\t%s = %s\n", name, val); 
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_ASSIGN_1 */
    scan_test_set(NULL, &ASSIGN_stop, &ASSIGN_stop);
   }
}

static char* BOOL(void)
{
  char* result;
  char* val1;
  char* val2;
  {
    val1 = SUM();
     result = val1; 
    if (scan_test_set(NULL, &rdp_BOOL_6_first, NULL))
    { /* Start of rdp_BOOL_6 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_26 /* == */, NULL))
          {
            scan_test(NULL, RDP_T_26 /* == */, &BOOL_stop);
            scan_();
            val2 = SUM();
             result = new_temp(); \
                                fprintf(fp, "\t%s = %s == %s\n", result, val1, val2); \
                                val1 = result; \
                             
          }
          else
          if (scan_test(NULL, RDP_T_28 /* >= */, NULL))
          {
            scan_test(NULL, RDP_T_28 /* >= */, &BOOL_stop);
            scan_();
            val2 = SUM();
             result = new_temp(); \
                                fprintf(fp, "\t%s = %s >= %s\n", result, val1, val2); \
                                val1 = result; \
                             
          }
          else
          if (scan_test(NULL, RDP_T_27 /* > */, NULL))
          {
            scan_test(NULL, RDP_T_27 /* > */, &BOOL_stop);
            scan_();
            val2 = SUM();
             result = new_temp(); \
                                        fprintf(fp, "\t%s = %s > %s\n", result, val1, val2); \
                                        val1 = result; \
                                 
          }
          else
          if (scan_test(NULL, RDP_T_24 /* <= */, NULL))
          {
            scan_test(NULL, RDP_T_24 /* <= */, &BOOL_stop);
            scan_();
            val2 = SUM();
             result = new_temp(); \
                                        fprintf(fp, "\t%s = %s <= %s\n", result, val1, val2); \
                                        val1 = result; \
                                 
          }
          else
          if (scan_test(NULL, RDP_T_23 /* < */, NULL))
          {
            scan_test(NULL, RDP_T_23 /* < */, &BOOL_stop);
            scan_();
            val2 = SUM();
             result = new_temp(); \
                                        fprintf(fp, "\t%s = %s < %s\n", result, val1, val2); \
                                        val1 = result; \
                                 
          }
          else
          if (scan_test(NULL, RDP_T_17 /* != */, NULL))
          {
            scan_test(NULL, RDP_T_17 /* != */, &BOOL_stop);
            scan_();
            val2 = SUM();
             result = new_temp(); \
                                        fprintf(fp, "\t%s = %s != %s\n", result, val1, val2); \
                                        val1 = result; \
                                 
          }
          else
            scan_test_set(NULL, &rdp_BOOL_6_first, &BOOL_stop)          ;
          }
        if (!scan_test_set(NULL, &rdp_BOOL_6_first, NULL)) break;
      }
    } /* end of rdp_BOOL_6 */
    scan_test_set(NULL, &BOOL_stop, &BOOL_stop);
   }
  return result;
}

static void BREAK(void)
{
  {
    scan_test(NULL, RDP_T_break, &BREAK_stop);
    scan_();
     char* label = end(loop_stack); \
                                         if (!label) { \
                                                text_message(TEXT_ERROR, "use of 'break' must be within a loop\n"); \
                                         } else { \
                                                fprintf(fp, "\tgoto %s\n", label); \
                                         } \
                                  
    scan_test_set(NULL, &BREAK_stop, &BREAK_stop);
   }
}

static void COMP_STMT(void)
{
  {
    if (scan_test_set(NULL, &rdp_COMP_STMT_1_first, NULL))
    { /* Start of rdp_COMP_STMT_1 */
      while (1)
      {
        {
          STMT();
          }
        if (!scan_test_set(NULL, &rdp_COMP_STMT_1_first, NULL)) break;
      }
    } /* end of rdp_COMP_STMT_1 */
    scan_test_set(NULL, &COMP_STMT_stop, &COMP_STMT_stop);
   }
}

static void COND(void)
{
  char* val;
  {
    scan_test(NULL, RDP_T_if, &COND_stop);
    scan_();
    scan_test(NULL, RDP_T_18 /* ( */, &COND_stop);
    scan_();
    val = EXPR();
    scan_test(NULL, RDP_T_19 /* ) */, &COND_stop);
    scan_();
     char* end = new_lab(); \
                    char* lab = new_lab(); \
                    fprintf(fp, "\tif %s == 0 goto %s\n", val, lab); \
             
    scan_test(NULL, RDP_T_37 /* { */, &COND_stop);
    scan_();
    COMP_STMT();
    scan_test(NULL, RDP_T_38 /* } */, &COND_stop);
    scan_();
     fprintf(fp, "\tgoto %s\n", end); \
                    fprintf(fp, "%s\n", lab); \
             
    if (scan_test(NULL, RDP_T_elif, NULL))
    { /* Start of rdp_COND_1 */
      while (1)
      {
        {
          scan_test(NULL, RDP_T_elif, &COND_stop);
          scan_();
          scan_test(NULL, RDP_T_18 /* ( */, &COND_stop);
          scan_();
          val = EXPR();
          scan_test(NULL, RDP_T_19 /* ) */, &COND_stop);
          scan_();
           lab = new_lab(); \
                      fprintf(fp, "\tif %s == 0 goto %s\n", val, lab); \
                   
          scan_test(NULL, RDP_T_37 /* { */, &COND_stop);
          scan_();
          COMP_STMT();
          scan_test(NULL, RDP_T_38 /* } */, &COND_stop);
          scan_();
           fprintf(fp, "\tgoto %s\n", end); \
                      fprintf(fp, "%s\n", lab); \
               
          }
        if (!scan_test(NULL, RDP_T_elif, NULL)) break;
      }
    } /* end of rdp_COND_1 */
    if (scan_test(NULL, RDP_T_else, NULL))
    { /* Start of rdp_COND_3 */
      while (1)
      {
        {
          scan_test(NULL, RDP_T_else, &COND_stop);
          scan_();
          scan_test(NULL, RDP_T_37 /* { */, &COND_stop);
          scan_();
          COMP_STMT();
          scan_test(NULL, RDP_T_38 /* } */, &COND_stop);
          scan_();
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_COND_3 */
     fprintf(fp, "%s\n", end); 
    scan_test_set(NULL, &COND_stop, &COND_stop);
   }
}

static void CONTINUE(void)
{
  {
    scan_test(NULL, RDP_T_continue, &CONTINUE_stop);
    scan_();
     char* label = start(loop_stack); \
                                                   if (!label) { \
                                                       text_message(TEXT_ERROR, "use of 'continue' must be within a loop\n"); \
                                               } else { \
                                                       fprintf(fp, "\tgoto %s\n", label); \
                                               } \
                                        
    scan_test_set(NULL, &CONTINUE_stop, &CONTINUE_stop);
   }
}

static void DECL(void)
{
  char* name;
  char* val;
  {
    scan_test(NULL, RDP_T_int, &DECL_stop);
    scan_();
    scan_test(NULL, SCAN_P_ID, &DECL_stop);
    name = SCAN_CAST->id;
    scan_();
     if (symbol_lookup_key(global, &name, NULL)) { \
                            text_message(TEXT_ERROR, "redeclaration of '%s'\n", name); \
                        } else { \
                                symbol_insert_key(global, &name, sizeof(char*), sizeof(global_data)); \
                        }  \
                 
    if (scan_test(NULL, RDP_T_25 /* = */, NULL))
    { /* Start of rdp_DECL_1 */
      while (1)
      {
        {
          scan_test(NULL, RDP_T_25 /* = */, &DECL_stop);
          scan_();
          val = EXPR();
           fprintf(fp, "\t%s = %s\n", name, val); 
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_DECL_1 */
     fprintf(ft, "%s\n", name); // print new symbol table entry to file 
    scan_test(NULL, RDP_T_22 /* ; */, &DECL_stop);
    scan_();
    scan_test_set(NULL, &DECL_stop, &DECL_stop);
   }
}

static char* EXPR(void)
{
  char* result;
  {
    result = BOOL();
    scan_test_set(NULL, &EXPR_stop, &EXPR_stop);
   }
  return result;
}

static void JUMP_STMT(void)
{
  {
    if (scan_test(NULL, RDP_T_break, NULL))
    {
      BREAK();
    }
    else
    if (scan_test(NULL, RDP_T_continue, NULL))
    {
      CONTINUE();
    }
    else
      scan_test_set(NULL, &JUMP_STMT_first, &JUMP_STMT_stop)    ;
    scan_test_set(NULL, &JUMP_STMT_stop, &JUMP_STMT_stop);
   }
}

static void LOOP(void)
{
  char* val;
  {
    scan_test(NULL, RDP_T_while, &LOOP_stop);
    scan_();
     char* begin = new_lab(); \
                        char* end = new_lab(); \
                        push(loop_stack, begin, end); \
                        fprintf(fp, "%s\n", begin); \
                 
    scan_test(NULL, RDP_T_18 /* ( */, &LOOP_stop);
    scan_();
    val = BOOL();
    scan_test(NULL, RDP_T_19 /* ) */, &LOOP_stop);
    scan_();
     fprintf(fp, "\tif %s == 0 goto %s\n", val, end); 
    scan_test(NULL, RDP_T_37 /* { */, &LOOP_stop);
    scan_();
    COMP_STMT();
    scan_test(NULL, RDP_T_38 /* } */, &LOOP_stop);
    scan_();
     fprintf(fp, "\tgoto %s\n", begin); \
                        fprintf(fp, "%s\n", end); \
                        char* label = pop(loop_stack); \
                 
    scan_test_set(NULL, &LOOP_stop, &LOOP_stop);
   }
}

static char* PRIMITIVE(void)
{
  char* result;
  long int val;
  char* name;
  {
    if (scan_test(NULL, SCAN_P_INTEGER, NULL))
    {
      scan_test(NULL, SCAN_P_INTEGER, &PRIMITIVE_stop);
      val = SCAN_CAST->data.i;
      scan_();
       result = (char*) mem_malloc(12); \
                               sprintf(result, "%li", val);  \
                            
    }
    else
    if (scan_test(NULL, SCAN_P_ID, NULL))
    {
      scan_test(NULL, SCAN_P_ID, &PRIMITIVE_stop);
      name = SCAN_CAST->id;
      scan_();
       if (!symbol_lookup_key(global, &name, NULL)) { \
                                   text_message(TEXT_ERROR, "'%s' undeclared\n", name); \
                               } else { \
                                   result = name;  \
                               } \
                            
    }
    else
      scan_test_set(NULL, &PRIMITIVE_first, &PRIMITIVE_stop)    ;
    scan_test_set(NULL, &PRIMITIVE_stop, &PRIMITIVE_stop);
   }
  return result;
}

static void PRINT(void)
{
  char* val;
  {
    scan_test(NULL, RDP_T_print, &PRINT_stop);
    scan_();
    scan_test(NULL, RDP_T_18 /* ( */, &PRINT_stop);
    scan_();
    val = EXPR();
    scan_test(NULL, RDP_T_19 /* ) */, &PRINT_stop);
    scan_();
     fprintf(fp, "\tprint %s\n", val); \
                  
    scan_test_set(NULL, &PRINT_stop, &PRINT_stop);
   }
}

static void STMT(void)
{
  {
    if (scan_test_set(NULL, &rdp_STMT_4_first, NULL))
    {
      { /* Start of rdp_STMT_3 */
        while (1)
        {
          scan_test_set(NULL, &rdp_STMT_3_first, &STMT_stop);
          {
            if (scan_test(NULL, SCAN_P_ID, NULL))
            {
              ASSIGN();
            }
            else
            if (scan_test(NULL, RDP_T_print, NULL))
            {
              PRINT();
            }
            else
            if (scan_test_set(NULL, &rdp_STMT_2_first, NULL))
            {
              JUMP_STMT();
            }
            else
              scan_test_set(NULL, &rdp_STMT_3_first, &STMT_stop)            ;
            }
          break;   /* hi limit is 1! */
        }
      } /* end of rdp_STMT_3 */
      scan_test(NULL, RDP_T_22 /* ; */, &STMT_stop);
      scan_();
    }
    else
    if (scan_test(NULL, RDP_T_if, NULL))
    {
      COND();
    }
    else
    if (scan_test(NULL, RDP_T_while, NULL))
    {
      LOOP();
    }
    else
      scan_test_set(NULL, &STMT_first, &STMT_stop)    ;
    scan_test_set(NULL, &STMT_stop, &STMT_stop);
   }
}

static char* SUM(void)
{
  char* result;
  char* val1;
  char* val2;
  {
    val1 = UNARY();
     result = val1; 
    if (scan_test_set(NULL, &rdp_SUM_2_first, NULL))
    { /* Start of rdp_SUM_2 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_20 /* + */, NULL))
          {
            scan_test(NULL, RDP_T_20 /* + */, &SUM_stop);
            scan_();
            val2 = UNARY();
             result = new_temp(); \
                           fprintf(fp, "\t%s = %s + %s\n", result, val1, val2); \
                           val1 = result; \
                        
          }
          else
          if (scan_test(NULL, RDP_T_21 /* - */, NULL))
          {
            scan_test(NULL, RDP_T_21 /* - */, &SUM_stop);
            scan_();
            val2 = UNARY();
             result = new_temp(); \
                           fprintf(fp, "\t%s = %s - %s\n", result, val1, val2); \
                           val1 = result; \
                        
          }
          else
            scan_test_set(NULL, &rdp_SUM_2_first, &SUM_stop)          ;
          }
        if (!scan_test_set(NULL, &rdp_SUM_2_first, NULL)) break;
      }
    } /* end of rdp_SUM_2 */
    scan_test_set(NULL, &SUM_stop, &SUM_stop);
   }
  return result;
}

void TRNS_UNIT(void)
{
  {
     fp = fopen("eac.tac", "w");  \
                                 ft = fopen("eac.tbl", "w");  \
                                 loop_stack = create_label_stack(); \
                          
    if (scan_test_set(NULL, &rdp_TRNS_UNIT_2_first, NULL))
    { /* Start of rdp_TRNS_UNIT_2 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_int, NULL))
          {
            DECL();
          }
          else
          if (scan_test_set(NULL, &rdp_TRNS_UNIT_1_first, NULL))
          {
            STMT();
          }
          else
            scan_test_set(NULL, &rdp_TRNS_UNIT_2_first, &TRNS_UNIT_stop)          ;
          }
        if (!scan_test_set(NULL, &rdp_TRNS_UNIT_2_first, NULL)) break;
      }
    } /* end of rdp_TRNS_UNIT_2 */
     fclose(fp);  \
                                 fclose(ft); \
                                 free(loop_stack);  \
                          
    scan_test_set(NULL, &TRNS_UNIT_stop, &TRNS_UNIT_stop);
   }
}

static char* UNARY(void)
{
  char* result;
  char* val1;
  {
    val1 = PRIMITIVE();
     result = new_temp(); \
                               fprintf(fp, "\t%s = %s\n", result, val1); \
                               val1 = result; \
                        
    scan_test_set(NULL, &UNARY_stop, &UNARY_stop);
   }
  return result;
}

int main(int argc, char *argv[])
{
  clock_t rdp_finish_time, rdp_start_time = clock();
  int
    rdp_symbol_statistics = 0,    /* show symbol_ table statistics flag */
    rdp_line_echo_all = 0,        /* make a listing on all passes flag */
    rdp_filter = 0,               /* filter flag */
    rdp_line_echo = 0;            /* make listing flag */

  unsigned long rdp_textsize = 35000l;   /* size of scanner text array */

  unsigned long rdp_tabwidth = 8l;   /* tab expansion width */

  char* rdp_vcg_filename = NULL;      /* filename for -V option */

  arg_message("rdparser\n" RDP_STAMP "\n\n""Usage:  [options] source");

  arg_message("");
  arg_boolean('f', "Filter mode (read from stdin and write to stdout)", &rdp_filter);
  arg_boolean('l', "Make a listing", &rdp_line_echo);
  arg_string ('o', "Write output to filename", &rdp_outputfilename);
  arg_boolean('s', "Echo each scanner symbol as it is read", &rdp_symbol_echo);
  arg_boolean('S', "Print summary symbol table statistics", &rdp_symbol_statistics);
  arg_numeric('t', "Tab expansion width (default 8)", &rdp_tabwidth);
  arg_numeric('T', "Text buffer size in bytes for scanner (default 20000)", &rdp_textsize);
  arg_boolean('v', "Set verbose mode", &rdp_verbose);
  arg_string ('V', "Write derivation tree to filename in VCG format", &rdp_vcg_filename);

  rdp_sourcefilename = *arg_process(argc, argv);

  if (rdp_filter)
{
    rdp_sourcefilename = "-";
    rdp_outputfilename = "-";

}
  if (rdp_sourcefilename == NULL)
     arg_help("No source file specified");

  rdp_sourcefilename = text_default_filetype(rdp_sourcefilename, "");
  text_init(rdp_textsize, 25, 100, (int) rdp_tabwidth);
  scan_init(0, 0, 0, rdp_symbol_echo, rdp_tokens);
  global = symbol_new_table("global", 101, 31, symbol_compare_string, symbol_hash_string, symbol_print_string);
  rdp_set_initialise();
  rdp_load_keywords();
  if (rdp_verbose)
     text_printf("\nrdparser\n" RDP_STAMP "\n\n");
  for (rdp_pass = 1; rdp_pass <= RDP_PASSES; rdp_pass++)
  {
    text_echo(rdp_line_echo_all || (rdp_line_echo && rdp_pass == RDP_PASSES));
    if (text_open(rdp_sourcefilename) == NULL)
      arg_help("unable to open source file");

    text_get_char();
    scan_();

    TRNS_UNIT();            /* call parser at top level */
    if (text_total_errors() != 0)
      text_message(TEXT_FATAL, "error%s detected in source file\n", text_total_errors() == 1 ? "" : "s");   /* crash quietly */ 
  }
  if (rdp_symbol_statistics)
    symbol_print_all_table_statistics(11);

  text_print_total_errors();
  if (rdp_verbose)
  {
    rdp_finish_time = clock();
    text_message(TEXT_INFO, "%.3f CPU seconds used\n", ((double) (rdp_finish_time-rdp_start_time)) / CLOCKS_PER_SEC);
  }
  return rdp_error_return;
}

/* End of .c */
