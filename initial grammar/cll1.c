/*******************************************************************************
*
* Parser generated by RDP on Dec 06 2020 18:08:47 from cll1.bnf
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
#include "cll1.h"

char
 *rdp_sourcefilename = NULL,   /* source file name */
 *rdp_outputfilename = "cll1.out";         /* output file name */

int
  rdp_symbol_echo = 0,                 /* symbol echo flag */
  rdp_verbose = 0,                     /* verbosity flag */
  rdp_pass;                            /* pass number */

int rdp_error_return = 0;              /* return value for main routine */

char *rdp_tokens = "IGNORE\0" 
"ID\0" "INTEGER\0" "REAL\0" "CHAR\0" "CHAR_ESC\0" "STRING\0" "STRING_ESC\0" "COMMENT\0" 
"COMMENT_VISIBLE\0" "COMMENT_NEST\0" "COMMENT_NEST_VISIBLE\0" "COMMENT_LINE\0" "COMMENT_LINE_VISIBLE\0" "EOF\0" "EOLN\0" "'!'\0" 
"'!='\0" "'('\0" "')'\0" "'*'\0" "'+'\0" "','\0" "';'\0" "'<'\0" 
"'<='\0" "'='\0" "'=='\0" "'>'\0" "'>='\0" "'int'\0" "'return'\0" "'while'\0" 
"'{'\0" "'}'\0" ;


/* Tree update function for noterminal nodes */
int rdp_tree_update = 0;

rdp_tree_data* rdp_add_child(char* id, rdp_tree_data* rdp_tree)
{
  rdp_tree_data* child;

  if (rdp_tree_update)
  {
    child  = (rdp_tree_data*) graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree);

    child->id = id;
    return child;
  }
  else
    return NULL;
}

/* Load keywords */
static void rdp_load_keywords(void)
{
  scan_load_keyword("!", NULL, RDP_T_16 /* ! */, SCAN_P_IGNORE);
  scan_load_keyword("!=", NULL, RDP_T_17 /* != */, SCAN_P_IGNORE);
  scan_load_keyword("(", NULL, RDP_T_18 /* ( */, SCAN_P_IGNORE);
  scan_load_keyword(")", NULL, RDP_T_19 /* ) */, SCAN_P_IGNORE);
  scan_load_keyword("*", NULL, RDP_T_20 /* * */, SCAN_P_IGNORE);
  scan_load_keyword("+", NULL, RDP_T_21 /* + */, SCAN_P_IGNORE);
  scan_load_keyword(",", NULL, RDP_T_22 /* , */, SCAN_P_IGNORE);
  scan_load_keyword(";", NULL, RDP_T_23 /* ; */, SCAN_P_IGNORE);
  scan_load_keyword("<", NULL, RDP_T_24 /* < */, SCAN_P_IGNORE);
  scan_load_keyword("<=", NULL, RDP_T_25 /* <= */, SCAN_P_IGNORE);
  scan_load_keyword("=", NULL, RDP_T_26 /* = */, SCAN_P_IGNORE);
  scan_load_keyword("==", NULL, RDP_T_27 /* == */, SCAN_P_IGNORE);
  scan_load_keyword(">", NULL, RDP_T_28 /* > */, SCAN_P_IGNORE);
  scan_load_keyword(">=", NULL, RDP_T_29 /* >= */, SCAN_P_IGNORE);
  scan_load_keyword("int", NULL, RDP_T_int, SCAN_P_IGNORE);
  scan_load_keyword("return", NULL, RDP_T_return, SCAN_P_IGNORE);
  scan_load_keyword("while", NULL, RDP_T_while, SCAN_P_IGNORE);
  scan_load_keyword("{", NULL, RDP_T_33 /* { */, SCAN_P_IGNORE);
  scan_load_keyword("}", NULL, RDP_T_34 /* } */, SCAN_P_IGNORE);
}

/* Set declarations */

  set_ ASSIGN_stop = SET_NULL;
  set_ BOOL_EXPR_first = SET_NULL;
  set_ BOOL_EXPR_stop = SET_NULL;
  set_ BOOL_OP_first = SET_NULL;
  set_ BOOL_OP_stop = SET_NULL;
  set_ CMPD_STMT_stop = SET_NULL;
  set_ DECL_first = SET_NULL;
  set_ DECL_stop = SET_NULL;
  set_ DECL_LIST_first = SET_NULL;
  set_ DECL_LIST_stop = SET_NULL;
  set_ EXPR_first = SET_NULL;
  set_ EXPR_stop = SET_NULL;
  set_ EXTN_DECL_stop = SET_NULL;
  set_ FUNC_DEFN_stop = SET_NULL;
  set_ INTL_DECL_stop = SET_NULL;
  set_ ITER_STMT_stop = SET_NULL;
  set_ JUMP_STMT_stop = SET_NULL;
  set_ MATH_EXPR_first = SET_NULL;
  set_ MATH_EXPR_stop = SET_NULL;
  set_ PARAMS_stop = SET_NULL;
  set_ PRIMARY_first = SET_NULL;
  set_ PRIMARY_stop = SET_NULL;
  set_ STMT_first = SET_NULL;
  set_ STMT_stop = SET_NULL;
  set_ TERM_STMT_first = SET_NULL;
  set_ TERM_STMT_stop = SET_NULL;
  set_ TRNS_UNIT_stop = SET_NULL;
  set_ TYPE_SPEC_stop = SET_NULL;
  set_ UNARY_OP_first = SET_NULL;
  set_ UNARY_OP_stop = SET_NULL;
  set_ rdp_BOOL_EXPR_0_first = SET_NULL;
  set_ rdp_BOOL_EXPR_1_first = SET_NULL;
  set_ rdp_BOOL_EXPR_2_first = SET_NULL;
  set_ rdp_CMPD_STMT_1_first = SET_NULL;
  set_ rdp_CMPD_STMT_2_first = SET_NULL;
  set_ rdp_DECL_1_first = SET_NULL;
  set_ rdp_DECL_LIST_2_first = SET_NULL;
  set_ rdp_EXPR_1_first = SET_NULL;
  set_ rdp_EXPR_2_first = SET_NULL;
  set_ rdp_EXPR_3_first = SET_NULL;
  set_ rdp_ITER_STMT_1_first = SET_NULL;
  set_ rdp_ITER_STMT_2_first = SET_NULL;
  set_ rdp_MATH_EXPR_0_first = SET_NULL;
  set_ rdp_MATH_EXPR_1_first = SET_NULL;
  set_ rdp_STMT_0_first = SET_NULL;
  set_ rdp_TERM_STMT_1_first = SET_NULL;
  set_ rdp_TERM_STMT_2_first = SET_NULL;
  set_ rdp_TERM_STMT_3_first = SET_NULL;

/* Initialise sets */

static void rdp_set_initialise(void)
{
  set_assign_list(&ASSIGN_stop, SCAN_P_EOF, RDP_T_19 /* ) */, RDP_T_23 /* ; */,SET_END);
  set_assign_list(&BOOL_EXPR_first, RDP_T_17 /* != */, RDP_T_24 /* < */, RDP_T_25 /* <= */, RDP_T_27 /* == */, RDP_T_28 /* > */, 
RDP_T_29 /* >= */, SET_END);
  set_assign_list(&BOOL_EXPR_stop, SCAN_P_EOF, RDP_T_19 /* ) */, RDP_T_23 /* ; */,SET_END);
  set_assign_list(&BOOL_OP_first, RDP_T_17 /* != */, RDP_T_24 /* < */, RDP_T_25 /* <= */, RDP_T_27 /* == */, RDP_T_28 /* > */, 
RDP_T_29 /* >= */, SET_END);
  set_assign_list(&BOOL_OP_stop, SCAN_P_ID, SCAN_P_INTEGER, SCAN_P_EOF,SET_END);
  set_assign_list(&CMPD_STMT_stop, SCAN_P_ID, SCAN_P_INTEGER, SCAN_P_EOF, RDP_T_int, RDP_T_return, RDP_T_while, RDP_T_34 /* } */,SET_END);
  set_assign_list(&DECL_first, RDP_T_18 /* ( */, RDP_T_22 /* , */, RDP_T_23 /* ; */, SET_END);
  set_assign_list(&DECL_stop, SCAN_P_EOF, RDP_T_int,SET_END);
  set_assign_list(&DECL_LIST_first, RDP_T_22 /* , */, RDP_T_23 /* ; */, SET_END);
  set_assign_list(&DECL_LIST_stop, SCAN_P_ID, SCAN_P_INTEGER, SCAN_P_EOF, RDP_T_int, RDP_T_return, RDP_T_while, RDP_T_34 /* } */,SET_END);
  set_assign_list(&EXPR_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&EXPR_stop, SCAN_P_EOF, RDP_T_19 /* ) */, RDP_T_23 /* ; */,SET_END);
  set_assign_list(&EXTN_DECL_stop, SCAN_P_EOF, RDP_T_int,SET_END);
  set_assign_list(&FUNC_DEFN_stop, SCAN_P_EOF, RDP_T_int,SET_END);
  set_assign_list(&INTL_DECL_stop, SCAN_P_ID, SCAN_P_INTEGER, SCAN_P_EOF, RDP_T_int, RDP_T_return, RDP_T_while, RDP_T_34 /* } */,SET_END);
  set_assign_list(&ITER_STMT_stop, SCAN_P_ID, SCAN_P_INTEGER, SCAN_P_EOF, RDP_T_int, RDP_T_return, RDP_T_while, RDP_T_34 /* } */,SET_END);
  set_assign_list(&JUMP_STMT_stop, SCAN_P_EOF, RDP_T_23 /* ; */,SET_END);
  set_assign_list(&MATH_EXPR_first, RDP_T_17 /* != */, RDP_T_20 /* * */, RDP_T_21 /* + */, RDP_T_24 /* < */, RDP_T_25 /* <= */, 
RDP_T_27 /* == */, RDP_T_28 /* > */, RDP_T_29 /* >= */, SET_END);
  set_assign_list(&MATH_EXPR_stop, SCAN_P_EOF, RDP_T_19 /* ) */, RDP_T_23 /* ; */,SET_END);
  set_assign_list(&PARAMS_stop, SCAN_P_EOF, RDP_T_19 /* ) */,SET_END);
  set_assign_list(&PRIMARY_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&PRIMARY_stop, SCAN_P_EOF, RDP_T_17 /* != */, RDP_T_19 /* ) */, RDP_T_20 /* * */, RDP_T_21 /* + */, 
RDP_T_23 /* ; */, RDP_T_24 /* < */, RDP_T_25 /* <= */, RDP_T_26 /* = */, RDP_T_27 /* == */, 
RDP_T_28 /* > */, RDP_T_29 /* >= */,SET_END);
  set_assign_list(&STMT_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_return, RDP_T_while, SET_END);
  set_assign_list(&STMT_stop, SCAN_P_ID, SCAN_P_INTEGER, SCAN_P_EOF, RDP_T_int, RDP_T_return, RDP_T_while, RDP_T_34 /* } */,SET_END);
  set_assign_list(&TERM_STMT_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_return, SET_END);
  set_assign_list(&TERM_STMT_stop, SCAN_P_ID, SCAN_P_INTEGER, SCAN_P_EOF, RDP_T_int, RDP_T_return, RDP_T_while, RDP_T_34 /* } */,SET_END);
  set_assign_list(&TRNS_UNIT_stop, SCAN_P_EOF,SET_END);
  set_assign_list(&TYPE_SPEC_stop, SCAN_P_ID, SCAN_P_EOF,SET_END);
  set_assign_list(&UNARY_OP_first, RDP_T_20 /* * */, RDP_T_21 /* + */, SET_END);
  set_assign_list(&UNARY_OP_stop, SCAN_P_ID, SCAN_P_INTEGER, SCAN_P_EOF,SET_END);
  set_assign_list(&rdp_BOOL_EXPR_0_first, RDP_T_17 /* != */, RDP_T_24 /* < */, RDP_T_25 /* <= */, RDP_T_27 /* == */, RDP_T_28 /* > */, 
RDP_T_29 /* >= */, SET_END);
  set_assign_list(&rdp_BOOL_EXPR_1_first, RDP_T_17 /* != */, RDP_T_24 /* < */, RDP_T_25 /* <= */, RDP_T_27 /* == */, RDP_T_28 /* > */, 
RDP_T_29 /* >= */, SET_END);
  set_assign_list(&rdp_BOOL_EXPR_2_first, RDP_T_17 /* != */, RDP_T_24 /* < */, RDP_T_25 /* <= */, RDP_T_27 /* == */, RDP_T_28 /* > */, 
RDP_T_29 /* >= */, SET_END);
  set_assign_list(&rdp_CMPD_STMT_1_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_return, RDP_T_while, SET_END);
  set_assign_list(&rdp_CMPD_STMT_2_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_int, RDP_T_return, RDP_T_while, SET_END);
  set_assign_list(&rdp_DECL_1_first, RDP_T_22 /* , */, RDP_T_23 /* ; */, SET_END);
  set_assign_list(&rdp_DECL_LIST_2_first, RDP_T_22 /* , */, RDP_T_23 /* ; */, SET_END);
  set_assign_list(&rdp_EXPR_1_first, RDP_T_17 /* != */, RDP_T_20 /* * */, RDP_T_21 /* + */, RDP_T_24 /* < */, RDP_T_25 /* <= */, 
RDP_T_27 /* == */, RDP_T_28 /* > */, RDP_T_29 /* >= */, SET_END);
  set_assign_list(&rdp_EXPR_2_first, RDP_T_17 /* != */, RDP_T_20 /* * */, RDP_T_21 /* + */, RDP_T_24 /* < */, RDP_T_25 /* <= */, 
RDP_T_26 /* = */, RDP_T_27 /* == */, RDP_T_28 /* > */, RDP_T_29 /* >= */, SET_END);
  set_assign_list(&rdp_EXPR_3_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&rdp_ITER_STMT_1_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_return, RDP_T_while, SET_END);
  set_assign_list(&rdp_ITER_STMT_2_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_return, RDP_T_while, RDP_T_33 /* { */, SET_END);
  set_assign_list(&rdp_MATH_EXPR_0_first, RDP_T_20 /* * */, RDP_T_21 /* + */, SET_END);
  set_assign_list(&rdp_MATH_EXPR_1_first, RDP_T_17 /* != */, RDP_T_24 /* < */, RDP_T_25 /* <= */, RDP_T_27 /* == */, RDP_T_28 /* > */, 
RDP_T_29 /* >= */, SET_END);
  set_assign_list(&rdp_STMT_0_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_return, SET_END);
  set_assign_list(&rdp_TERM_STMT_1_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&rdp_TERM_STMT_2_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_return, SET_END);
  set_assign_list(&rdp_TERM_STMT_3_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_return, SET_END);
}

/* Parser forward declarations and macros */
static void ASSIGN(rdp_tree_data* rdp_tree);
static void BOOL_EXPR(rdp_tree_data* rdp_tree);
static void BOOL_OP(rdp_tree_data* rdp_tree);
static void CMPD_STMT(rdp_tree_data* rdp_tree);
static void DECL(rdp_tree_data* rdp_tree);
static void DECL_LIST(rdp_tree_data* rdp_tree);
static void EXPR(rdp_tree_data* rdp_tree);
static void EXTN_DECL(rdp_tree_data* rdp_tree);
static void FUNC_DEFN(rdp_tree_data* rdp_tree);
static void INTL_DECL(rdp_tree_data* rdp_tree);
static void ITER_STMT(rdp_tree_data* rdp_tree);
static void JUMP_STMT(rdp_tree_data* rdp_tree);
static void MATH_EXPR(rdp_tree_data* rdp_tree);
static void PARAMS(rdp_tree_data* rdp_tree);
static void PRIMARY(rdp_tree_data* rdp_tree);
static void STMT(rdp_tree_data* rdp_tree);
static void TERM_STMT(rdp_tree_data* rdp_tree);
void TRNS_UNIT(rdp_tree_data* rdp_tree);
static void TYPE_SPEC(rdp_tree_data* rdp_tree);
static void UNARY_OP(rdp_tree_data* rdp_tree);

/* Parser functions */
static void ASSIGN(rdp_tree_data* rdp_tree)
{
  {
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_26 /* = */, &ASSIGN_stop);
    scan_();
    PRIMARY(rdp_add_child("PRIMARY", rdp_tree));
    MATH_EXPR(rdp_add_child("MATH_EXPR", rdp_tree));
    scan_test_set(NULL, &ASSIGN_stop, &ASSIGN_stop);
   }
}

static void BOOL_EXPR(rdp_tree_data* rdp_tree)
{
  {
    if (scan_test_set(NULL, &rdp_BOOL_EXPR_1_first, NULL))
    { /* Start of rdp_BOOL_EXPR_1 */
      while (1)
      {
        {
          BOOL_OP(rdp_add_child("BOOL_OP", rdp_tree));
          PRIMARY(rdp_add_child("PRIMARY", rdp_tree));
          }
        if (!scan_test_set(NULL, &rdp_BOOL_EXPR_1_first, NULL)) break;
      }
    } /* end of rdp_BOOL_EXPR_1 */
    else
    {
      /* default action processing for rdp_BOOL_EXPR_1*/
      if (rdp_tree_update) {rdp_tree_data *temp = (rdp_tree_data*) graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree); temp->id = ""; temp->token = SCAN_P_ID;}
    }
    scan_test_set(NULL, &BOOL_EXPR_stop, &BOOL_EXPR_stop);
   }
}

static void BOOL_OP(rdp_tree_data* rdp_tree)
{
  {
    if (scan_test(NULL, RDP_T_27 /* == */, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, RDP_T_27 /* == */, &BOOL_OP_stop);
      scan_();
    }
    else
    if (scan_test(NULL, RDP_T_17 /* != */, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, RDP_T_17 /* != */, &BOOL_OP_stop);
      scan_();
    }
    else
    if (scan_test(NULL, RDP_T_28 /* > */, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, RDP_T_28 /* > */, &BOOL_OP_stop);
      scan_();
    }
    else
    if (scan_test(NULL, RDP_T_24 /* < */, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, RDP_T_24 /* < */, &BOOL_OP_stop);
      scan_();
    }
    else
    if (scan_test(NULL, RDP_T_29 /* >= */, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, RDP_T_29 /* >= */, &BOOL_OP_stop);
      scan_();
    }
    else
    if (scan_test(NULL, RDP_T_25 /* <= */, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, RDP_T_25 /* <= */, &BOOL_OP_stop);
      scan_();
    }
    else
      scan_test_set(NULL, &BOOL_OP_first, &BOOL_OP_stop)    ;
    scan_test_set(NULL, &BOOL_OP_stop, &BOOL_OP_stop);
   }
}

static void CMPD_STMT(rdp_tree_data* rdp_tree)
{
  {
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_33 /* { */, &CMPD_STMT_stop);
    scan_();
    if (scan_test_set(NULL, &rdp_CMPD_STMT_2_first, NULL))
    { /* Start of rdp_CMPD_STMT_2 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_int, NULL))
          {
            INTL_DECL(rdp_add_child("INTL_DECL", rdp_tree));
          }
          else
          if (scan_test_set(NULL, &rdp_CMPD_STMT_1_first, NULL))
          {
            STMT(rdp_add_child("STMT", rdp_tree));
          }
          else
            scan_test_set(NULL, &rdp_CMPD_STMT_2_first, &CMPD_STMT_stop)          ;
          }
        if (!scan_test_set(NULL, &rdp_CMPD_STMT_2_first, NULL)) break;
      }
    } /* end of rdp_CMPD_STMT_2 */
    else
    {
      /* default action processing for rdp_CMPD_STMT_2*/
      if (rdp_tree_update) {rdp_tree_data *temp = (rdp_tree_data*) graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree); temp->id = ""; temp->token = SCAN_P_ID;}
    }
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_34 /* } */, &CMPD_STMT_stop);
    scan_();
    scan_test_set(NULL, &CMPD_STMT_stop, &CMPD_STMT_stop);
   }
}

static void DECL(rdp_tree_data* rdp_tree)
{
  {
    if (scan_test(NULL, RDP_T_18 /* ( */, NULL))
    {
      FUNC_DEFN(rdp_add_child("FUNC_DEFN", rdp_tree));
    }
    else
    if (scan_test_set(NULL, &rdp_DECL_1_first, NULL))
    {
      DECL_LIST(rdp_add_child("DECL_LIST", rdp_tree));
    }
    else
      scan_test_set(NULL, &DECL_first, &DECL_stop)    ;
    scan_test_set(NULL, &DECL_stop, &DECL_stop);
   }
}

static void DECL_LIST(rdp_tree_data* rdp_tree)
{
  {
    if (scan_test(NULL, RDP_T_22 /* , */, NULL))
    { /* Start of rdp_DECL_LIST_1 */
      while (1)
      {
        {
          if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
          scan_test(NULL, RDP_T_22 /* , */, &DECL_LIST_stop);
          scan_();
          if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
          scan_test(NULL, SCAN_P_ID, &DECL_LIST_stop);
          scan_();
          }
        if (!scan_test(NULL, RDP_T_22 /* , */, NULL)) break;
      }
    } /* end of rdp_DECL_LIST_1 */
    else
    {
      /* default action processing for rdp_DECL_LIST_1*/
      if (rdp_tree_update) {rdp_tree_data *temp = (rdp_tree_data*) graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree); temp->id = ""; temp->token = SCAN_P_ID;}
    }
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_23 /* ; */, &DECL_LIST_stop);
    scan_();
    scan_test_set(NULL, &DECL_LIST_stop, &DECL_LIST_stop);
   }
}

static void EXPR(rdp_tree_data* rdp_tree)
{
  {
    PRIMARY(rdp_add_child("PRIMARY", rdp_tree));
    { /* Start of rdp_EXPR_2 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_26 /* = */, NULL))
          {
            ASSIGN(rdp_add_child("ASSIGN", rdp_tree));
          }
          else
          if (scan_test_set(NULL, &rdp_EXPR_1_first, NULL))
          {
            MATH_EXPR(rdp_add_child("MATH_EXPR", rdp_tree));
          }
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_EXPR_2 */
    scan_test_set(NULL, &EXPR_stop, &EXPR_stop);
   }
}

static void EXTN_DECL(rdp_tree_data* rdp_tree)
{
  {
    TYPE_SPEC(rdp_add_child("TYPE_SPEC", rdp_tree));
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, SCAN_P_ID, &EXTN_DECL_stop);
    scan_();
    DECL(rdp_add_child("DECL", rdp_tree));
    scan_test_set(NULL, &EXTN_DECL_stop, &EXTN_DECL_stop);
   }
}

static void FUNC_DEFN(rdp_tree_data* rdp_tree)
{
  {
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_18 /* ( */, &FUNC_DEFN_stop);
    scan_();
    if (scan_test(NULL, RDP_T_int, NULL))
    { /* Start of rdp_FUNC_DEFN_1 */
      while (1)
      {
        {
          PARAMS(rdp_add_child("PARAMS", rdp_tree));
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_FUNC_DEFN_1 */
    else
    {
      /* default action processing for rdp_FUNC_DEFN_1*/
      if (rdp_tree_update) {rdp_tree_data *temp = (rdp_tree_data*) graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree); temp->id = ""; temp->token = SCAN_P_ID;}
    }
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_19 /* ) */, &FUNC_DEFN_stop);
    scan_();
    CMPD_STMT(rdp_add_child("CMPD_STMT", rdp_tree));
    scan_test_set(NULL, &FUNC_DEFN_stop, &FUNC_DEFN_stop);
   }
}

static void INTL_DECL(rdp_tree_data* rdp_tree)
{
  {
    TYPE_SPEC(rdp_add_child("TYPE_SPEC", rdp_tree));
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, SCAN_P_ID, &INTL_DECL_stop);
    scan_();
    DECL_LIST(rdp_add_child("DECL_LIST", rdp_tree));
    scan_test_set(NULL, &INTL_DECL_stop, &INTL_DECL_stop);
   }
}

static void ITER_STMT(rdp_tree_data* rdp_tree)
{
  {
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_while, &ITER_STMT_stop);
    scan_();
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_18 /* ( */, &ITER_STMT_stop);
    scan_();
    EXPR(rdp_add_child("EXPR", rdp_tree));
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_19 /* ) */, &ITER_STMT_stop);
    scan_();
    { /* Start of rdp_ITER_STMT_2 */
      while (1)
      {
        scan_test_set(NULL, &rdp_ITER_STMT_2_first, &ITER_STMT_stop);
        {
          if (scan_test(NULL, RDP_T_33 /* { */, NULL))
          {
            CMPD_STMT(rdp_add_child("CMPD_STMT", rdp_tree));
          }
          else
          if (scan_test_set(NULL, &rdp_ITER_STMT_1_first, NULL))
          {
            STMT(rdp_add_child("STMT", rdp_tree));
          }
          else
            scan_test_set(NULL, &rdp_ITER_STMT_2_first, &ITER_STMT_stop)          ;
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_ITER_STMT_2 */
    scan_test_set(NULL, &ITER_STMT_stop, &ITER_STMT_stop);
   }
}

static void JUMP_STMT(rdp_tree_data* rdp_tree)
{
  {
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_return, &JUMP_STMT_stop);
    scan_();
    EXPR(rdp_add_child("EXPR", rdp_tree));
    scan_test_set(NULL, &JUMP_STMT_stop, &JUMP_STMT_stop);
   }
}

static void MATH_EXPR(rdp_tree_data* rdp_tree)
{
  {
    if (scan_test_set(NULL, &rdp_MATH_EXPR_0_first, NULL))
    {
      UNARY_OP(rdp_add_child("UNARY_OP", rdp_tree));
      PRIMARY(rdp_add_child("PRIMARY", rdp_tree));
      MATH_EXPR(rdp_add_child("MATH_EXPR", rdp_tree));
    }
    else
    if (scan_test_set(NULL, &rdp_MATH_EXPR_1_first, NULL))
    {
      BOOL_EXPR(rdp_add_child("BOOL_EXPR", rdp_tree));
    }
    scan_test_set(NULL, &MATH_EXPR_stop, &MATH_EXPR_stop);
   }
}

static void PARAMS(rdp_tree_data* rdp_tree)
{
  {
    TYPE_SPEC(rdp_add_child("TYPE_SPEC", rdp_tree));
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, SCAN_P_ID, &PARAMS_stop);
    scan_();
    if (scan_test(NULL, RDP_T_22 /* , */, NULL))
    { /* Start of rdp_PARAMS_1 */
      while (1)
      {
        {
          if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
          scan_test(NULL, RDP_T_22 /* , */, &PARAMS_stop);
          scan_();
          TYPE_SPEC(rdp_add_child("TYPE_SPEC", rdp_tree));
          if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
          scan_test(NULL, SCAN_P_ID, &PARAMS_stop);
          scan_();
          }
        if (!scan_test(NULL, RDP_T_22 /* , */, NULL)) break;
      }
    } /* end of rdp_PARAMS_1 */
    else
    {
      /* default action processing for rdp_PARAMS_1*/
      if (rdp_tree_update) {rdp_tree_data *temp = (rdp_tree_data*) graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree); temp->id = ""; temp->token = SCAN_P_ID;}
    }
    scan_test_set(NULL, &PARAMS_stop, &PARAMS_stop);
   }
}

static void PRIMARY(rdp_tree_data* rdp_tree)
{
  {
    if (scan_test(NULL, SCAN_P_INTEGER, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, SCAN_P_INTEGER, &PRIMARY_stop);
      scan_();
    }
    else
    if (scan_test(NULL, SCAN_P_ID, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, SCAN_P_ID, &PRIMARY_stop);
      scan_();
    }
    else
      scan_test_set(NULL, &PRIMARY_first, &PRIMARY_stop)    ;
    scan_test_set(NULL, &PRIMARY_stop, &PRIMARY_stop);
   }
}

static void STMT(rdp_tree_data* rdp_tree)
{
  {
    if (scan_test_set(NULL, &rdp_STMT_0_first, NULL))
    {
      TERM_STMT(rdp_add_child("TERM_STMT", rdp_tree));
    }
    else
    if (scan_test(NULL, RDP_T_while, NULL))
    {
      ITER_STMT(rdp_add_child("ITER_STMT", rdp_tree));
    }
    else
      scan_test_set(NULL, &STMT_first, &STMT_stop)    ;
    scan_test_set(NULL, &STMT_stop, &STMT_stop);
   }
}

static void TERM_STMT(rdp_tree_data* rdp_tree)
{
  {
    { /* Start of rdp_TERM_STMT_2 */
      while (1)
      {
        scan_test_set(NULL, &rdp_TERM_STMT_2_first, &TERM_STMT_stop);
        {
          if (scan_test(NULL, RDP_T_return, NULL))
          {
            JUMP_STMT(rdp_add_child("JUMP_STMT", rdp_tree));
          }
          else
          if (scan_test_set(NULL, &rdp_TERM_STMT_1_first, NULL))
          {
            EXPR(rdp_add_child("EXPR", rdp_tree));
          }
          else
            scan_test_set(NULL, &rdp_TERM_STMT_2_first, &TERM_STMT_stop)          ;
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_TERM_STMT_2 */
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_23 /* ; */, &TERM_STMT_stop);
    scan_();
    scan_test_set(NULL, &TERM_STMT_stop, &TERM_STMT_stop);
   }
}

void TRNS_UNIT(rdp_tree_data* rdp_tree)
{
  {
    if (scan_test(NULL, RDP_T_int, NULL))
    { /* Start of rdp_TRNS_UNIT_1 */
      while (1)
      {
        {
          EXTN_DECL(rdp_add_child("EXTN_DECL", rdp_tree));
          }
        if (!scan_test(NULL, RDP_T_int, NULL)) break;
      }
    } /* end of rdp_TRNS_UNIT_1 */
    else
    {
      /* default action processing for rdp_TRNS_UNIT_1*/
      if (rdp_tree_update) {rdp_tree_data *temp = (rdp_tree_data*) graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree); temp->id = ""; temp->token = SCAN_P_ID;}
    }
    scan_test_set(NULL, &TRNS_UNIT_stop, &TRNS_UNIT_stop);
   }
}

static void TYPE_SPEC(rdp_tree_data* rdp_tree)
{
  {
    if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
    scan_test(NULL, RDP_T_int, &TYPE_SPEC_stop);
    scan_();
    scan_test_set(NULL, &TYPE_SPEC_stop, &TYPE_SPEC_stop);
   }
}

static void UNARY_OP(rdp_tree_data* rdp_tree)
{
  {
    if (scan_test(NULL, RDP_T_21 /* + */, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, RDP_T_21 /* + */, &UNARY_OP_stop);
      scan_();
    }
    else
    if (scan_test(NULL, RDP_T_20 /* * */, NULL))
    {
      if (rdp_tree_update) memcpy(graph_insert_node_child(sizeof(rdp_tree_data), 0, rdp_tree), text_scan_data, sizeof(scan_data));
      scan_test(NULL, RDP_T_20 /* * */, &UNARY_OP_stop);
      scan_();
    }
    else
      scan_test_set(NULL, &UNARY_OP_first, &UNARY_OP_stop)    ;
    scan_test_set(NULL, &UNARY_OP_stop, &UNARY_OP_stop);
   }
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

  rdp_tree_data* rdp_tree = (rdp_tree_data*) graph_insert_graph("RDP derivation tree");  /* hook for derivation tree */

  arg_message("rdparser\n" RDP_STAMP "\n\n""Usage: cll1 [options] source");

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
  rdp_set_initialise();
  rdp_load_keywords();
  if (rdp_verbose)
     text_printf("\nrdparser\n" RDP_STAMP "\n\n");
  for (rdp_pass = 1; rdp_pass <= RDP_PASSES; rdp_pass++)
  {
    rdp_tree_update = rdp_pass == RDP_PASSES;
    text_echo(rdp_line_echo_all || (rdp_line_echo && rdp_pass == RDP_PASSES));
    if (text_open(rdp_sourcefilename) == NULL)
      arg_help("unable to open source file");

    text_get_char();
    scan_();

    TRNS_UNIT(rdp_add_child("TRNS_UNIT", rdp_tree));            /* call parser at top level */
    if (text_total_errors() != 0)
      text_message(TEXT_FATAL, "error%s detected in source file\n", text_total_errors() == 1 ? "" : "s");   /* crash quietly */ 
  }
  if (rdp_symbol_statistics)
    symbol_print_all_table_statistics(11);

  scan_prune_tree((scan_data*) rdp_tree);
  if (rdp_vcg_filename != NULL)
  {
    FILE *rdp_vcg_file;

    if (*rdp_vcg_filename == '\0')   /* No filename supplied */
      rdp_vcg_filename = "rdparser";
    rdp_vcg_file = fopen((rdp_vcg_filename = text_default_filetype(rdp_vcg_filename, "vcg")), "w");

    if (rdp_vcg_file == NULL)
      text_message(TEXT_FATAL, "unable to open VCG file '%s' for write\n", rdp_vcg_filename);

    if (rdp_verbose)
      text_message(TEXT_INFO, "Dumping derivation tree to VCG file '%s'\n", rdp_vcg_filename);

    text_redirect(rdp_vcg_file);
    graph_vcg(rdp_tree, NULL, scan_vcg_print_node, NULL);
    text_redirect(stdout);
  }

  text_print_total_errors();
  if (rdp_verbose)
  {
    rdp_finish_time = clock();
    text_message(TEXT_INFO, "%.3f CPU seconds used\n", ((double) (rdp_finish_time-rdp_start_time)) / CLOCKS_PER_SEC);
  }
  return rdp_error_return;
}

/* End of cll1.c */