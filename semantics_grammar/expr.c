/*******************************************************************************
*
* Parser generated by RDP on Dec 06 2020 18:12:19 from expr.bnf
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
#include "expr.h"

char
 *rdp_sourcefilename = NULL,   /* source file name */
 *rdp_outputfilename = "expr.out";         /* output file name */

int
  rdp_symbol_echo = 0,                 /* symbol echo flag */
  rdp_verbose = 0,                     /* verbosity flag */
  rdp_pass;                            /* pass number */

int rdp_error_return = 0;              /* return value for main routine */

char *rdp_tokens = "IGNORE\0" 
"ID\0" "INTEGER\0" "REAL\0" "CHAR\0" "CHAR_ESC\0" "STRING\0" "STRING_ESC\0" "COMMENT\0" 
"COMMENT_VISIBLE\0" "COMMENT_NEST\0" "COMMENT_NEST_VISIBLE\0" "COMMENT_LINE\0" "COMMENT_LINE_VISIBLE\0" "EOF\0" "EOLN\0" "'!'\0" 
"'!='\0" "'*'\0" "'+'\0" "'-'\0" "';'\0" "'<'\0" "'<='\0" "'='\0" 
"'=='\0" "'>'\0" "'>='\0" "'int'\0" ;

global_data * global_temp = NULL;
void* global = NULL;

/* Load keywords */
static void rdp_load_keywords(void)
{
  scan_load_keyword("!", NULL, RDP_T_16 /* ! */, SCAN_P_IGNORE);
  scan_load_keyword("!=", NULL, RDP_T_17 /* != */, SCAN_P_IGNORE);
  scan_load_keyword("*", NULL, RDP_T_18 /* * */, SCAN_P_IGNORE);
  scan_load_keyword("+", NULL, RDP_T_19 /* + */, SCAN_P_IGNORE);
  scan_load_keyword("-", NULL, RDP_T_20 /* - */, SCAN_P_IGNORE);
  scan_load_keyword(";", NULL, RDP_T_21 /* ; */, SCAN_P_IGNORE);
  scan_load_keyword("<", NULL, RDP_T_22 /* < */, SCAN_P_IGNORE);
  scan_load_keyword("<=", NULL, RDP_T_23 /* <= */, SCAN_P_IGNORE);
  scan_load_keyword("=", NULL, RDP_T_24 /* = */, SCAN_P_IGNORE);
  scan_load_keyword("==", NULL, RDP_T_25 /* == */, SCAN_P_IGNORE);
  scan_load_keyword(">", NULL, RDP_T_26 /* > */, SCAN_P_IGNORE);
  scan_load_keyword(">=", NULL, RDP_T_27 /* >= */, SCAN_P_IGNORE);
  scan_load_keyword("int", NULL, RDP_T_int, SCAN_P_IGNORE);
}

/* Set declarations */

  set_ BOOL_first = SET_NULL;
  set_ BOOL_stop = SET_NULL;
  set_ DECLARATION_stop = SET_NULL;
  set_ EXPRESSION_first = SET_NULL;
  set_ EXPRESSION_stop = SET_NULL;
  set_ PRIMITIVE_first = SET_NULL;
  set_ PRIMITIVE_stop = SET_NULL;
  set_ PROD_first = SET_NULL;
  set_ PROD_stop = SET_NULL;
  set_ STATEMENT_stop = SET_NULL;
  set_ SUM_first = SET_NULL;
  set_ SUM_stop = SET_NULL;
  set_ TRANSLATION_UNIT_first = SET_NULL;
  set_ TRANSLATION_UNIT_stop = SET_NULL;
  set_ TYPE_SPECIFIER_stop = SET_NULL;
  set_ rdp_BOOL_6_first = SET_NULL;
  set_ rdp_BOOL_7_first = SET_NULL;
  set_ rdp_EXPRESSION_0_first = SET_NULL;
  set_ rdp_PROD_2_first = SET_NULL;
  set_ rdp_SUM_2_first = SET_NULL;
  set_ rdp_SUM_3_first = SET_NULL;
  set_ rdp_TRANSLATION_UNIT_2_first = SET_NULL;
  set_ rdp_TRANSLATION_UNIT_3_first = SET_NULL;

/* Initialise sets */

static void rdp_set_initialise(void)
{
  set_assign_list(&BOOL_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&BOOL_stop, SCAN_P_EOF, RDP_T_21 /* ; */,SET_END);
  set_assign_list(&DECLARATION_stop, SCAN_P_ID, SCAN_P_EOF, RDP_T_int,SET_END);
  set_assign_list(&EXPRESSION_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&EXPRESSION_stop, SCAN_P_EOF, RDP_T_21 /* ; */,SET_END);
  set_assign_list(&PRIMITIVE_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&PRIMITIVE_stop, SCAN_P_EOF, RDP_T_17 /* != */, RDP_T_18 /* * */, RDP_T_19 /* + */, RDP_T_20 /* - */, 
RDP_T_21 /* ; */, RDP_T_22 /* < */, RDP_T_23 /* <= */, RDP_T_25 /* == */, RDP_T_26 /* > */, 
RDP_T_27 /* >= */,SET_END);
  set_assign_list(&PROD_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&PROD_stop, SCAN_P_EOF, RDP_T_17 /* != */, RDP_T_19 /* + */, RDP_T_20 /* - */, RDP_T_21 /* ; */, 
RDP_T_22 /* < */, RDP_T_23 /* <= */, RDP_T_25 /* == */, RDP_T_26 /* > */, RDP_T_27 /* >= */,SET_END);
  set_assign_list(&STATEMENT_stop, SCAN_P_ID, SCAN_P_EOF, RDP_T_int,SET_END);
  set_assign_list(&SUM_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&SUM_stop, SCAN_P_EOF, RDP_T_17 /* != */, RDP_T_21 /* ; */, RDP_T_22 /* < */, RDP_T_23 /* <= */, 
RDP_T_25 /* == */, RDP_T_26 /* > */, RDP_T_27 /* >= */,SET_END);
  set_assign_list(&TRANSLATION_UNIT_first, SCAN_P_ID, RDP_T_int, SET_END);
  set_assign_list(&TRANSLATION_UNIT_stop, SCAN_P_EOF,SET_END);
  set_assign_list(&TYPE_SPECIFIER_stop, SCAN_P_ID, SCAN_P_EOF,SET_END);
  set_assign_list(&rdp_BOOL_6_first, RDP_T_17 /* != */, RDP_T_22 /* < */, RDP_T_23 /* <= */, RDP_T_25 /* == */, RDP_T_26 /* > */, 
RDP_T_27 /* >= */, SET_END);
  set_assign_list(&rdp_BOOL_7_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&rdp_EXPRESSION_0_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&rdp_PROD_2_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&rdp_SUM_2_first, RDP_T_19 /* + */, RDP_T_20 /* - */, SET_END);
  set_assign_list(&rdp_SUM_3_first, SCAN_P_ID, SCAN_P_INTEGER, SET_END);
  set_assign_list(&rdp_TRANSLATION_UNIT_2_first, SCAN_P_ID, RDP_T_int, SET_END);
  set_assign_list(&rdp_TRANSLATION_UNIT_3_first, SCAN_P_ID, RDP_T_int, SET_END);
}

/* Parser forward declarations and macros */
static int BOOL(void);
static int DECLARATION(void);
static int EXPRESSION(void);
static int PRIMITIVE(void);
static int PROD(void);
static int STATEMENT(void);
static int SUM(void);
void TRANSLATION_UNIT(void);
static void TYPE_SPECIFIER(void);

/* Parser functions */
static int BOOL(void)
{
  int result;
  int val;
  {
    result = SUM();
    if (scan_test_set(NULL, &rdp_BOOL_6_first, NULL))
    { /* Start of rdp_BOOL_6 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_25 /* == */, NULL))
          {
            scan_test(NULL, RDP_T_25 /* == */, &BOOL_stop);
            scan_();
            val = SUM();
             result = result == val; 
          }
          else
          if (scan_test(NULL, RDP_T_17 /* != */, NULL))
          {
            scan_test(NULL, RDP_T_17 /* != */, &BOOL_stop);
            scan_();
            val = SUM();
             result = result != val; 
          }
          else
          if (scan_test(NULL, RDP_T_27 /* >= */, NULL))
          {
            scan_test(NULL, RDP_T_27 /* >= */, &BOOL_stop);
            scan_();
            val = SUM();
             result = result >= val; 
          }
          else
          if (scan_test(NULL, RDP_T_23 /* <= */, NULL))
          {
            scan_test(NULL, RDP_T_23 /* <= */, &BOOL_stop);
            scan_();
            val = SUM();
             result = result <= val; 
          }
          else
          if (scan_test(NULL, RDP_T_26 /* > */, NULL))
          {
            scan_test(NULL, RDP_T_26 /* > */, &BOOL_stop);
            scan_();
            val = SUM();
             result = result >  val; 
          }
          else
          if (scan_test(NULL, RDP_T_22 /* < */, NULL))
          {
            scan_test(NULL, RDP_T_22 /* < */, &BOOL_stop);
            scan_();
            val = SUM();
             result = result <  val; 
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

static int DECLARATION(void)
{
  int result;
  char* name;
  {
    TYPE_SPECIFIER();
    scan_test(NULL, SCAN_P_ID, &DECLARATION_stop);
    name = SCAN_CAST->id;
    scan_();
    if (scan_test(NULL, RDP_T_24 /* = */, NULL))
    { /* Start of rdp_DECLARATION_1 */
      while (1)
      {
        {
          scan_test(NULL, RDP_T_24 /* = */, &DECLARATION_stop);
          scan_();
          result = EXPRESSION();
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_DECLARATION_1 */
    scan_test(NULL, RDP_T_21 /* ; */, &DECLARATION_stop);
    scan_();
     if (symbol_lookup_key(global, &name, NULL))  \
                                                        text_message(TEXT_ERROR, "redeclaration of '%s'\n", name); \
                                                else { \
                                                        global_cast(symbol_insert_key(global, &name, sizeof(char*), sizeof(global_data)))->i = result; \
                                                        printf("%d\n", result); \
                                                } \
                                         
    scan_test_set(NULL, &DECLARATION_stop, &DECLARATION_stop);
   }
  return result;
}

static int EXPRESSION(void)
{
  int result;
  {
    result = BOOL();
    scan_test_set(NULL, &EXPRESSION_stop, &EXPRESSION_stop);
   }
  return result;
}

static int PRIMITIVE(void)
{
  int result;
  char* name;
  {
    if (scan_test(NULL, SCAN_P_INTEGER, NULL))
    {
      scan_test(NULL, SCAN_P_INTEGER, &PRIMITIVE_stop);
      result = SCAN_CAST->data.i;
      scan_();
    }
    else
    if (scan_test(NULL, SCAN_P_ID, NULL))
    {
      scan_test(NULL, SCAN_P_ID, &PRIMITIVE_stop);
      name = SCAN_CAST->id;
      scan_();
       if (!symbol_lookup_key(global, &name, NULL)) \
                                                                        text_message(TEXT_ERROR, "'%s' undeclared\n", name); \
                                                                else \
                                                                        result = global_cast(symbol_lookup_key(global, &name, NULL))->i; \
                                                         
    }
    else
      scan_test_set(NULL, &PRIMITIVE_first, &PRIMITIVE_stop)    ;
    scan_test_set(NULL, &PRIMITIVE_stop, &PRIMITIVE_stop);
   }
  return result;
}

static int PROD(void)
{
  int result;
  int val;
  {
    result = PRIMITIVE();
    if (scan_test(NULL, RDP_T_18 /* * */, NULL))
    { /* Start of rdp_PROD_1 */
      while (1)
      {
        {
          scan_test(NULL, RDP_T_18 /* * */, &PROD_stop);
          scan_();
          val = PRIMITIVE();
           result *= val; 
          }
        if (!scan_test(NULL, RDP_T_18 /* * */, NULL)) break;
      }
    } /* end of rdp_PROD_1 */
    scan_test_set(NULL, &PROD_stop, &PROD_stop);
   }
  return result;
}

static int STATEMENT(void)
{
  int result;
  char* name;
  {
    scan_test(NULL, SCAN_P_ID, &STATEMENT_stop);
    name = SCAN_CAST->id;
    scan_();
     if (!symbol_lookup_key(global, &name, NULL))  \
                                                        text_message(TEXT_ERROR, "'%s' undeclared\n", name); \
                                                else \
                                                        result = global_cast(symbol_lookup_key(global, &name, NULL))->i; \
                                         
    if (scan_test(NULL, RDP_T_24 /* = */, NULL))
    { /* Start of rdp_STATEMENT_1 */
      while (1)
      {
        {
          scan_test(NULL, RDP_T_24 /* = */, &STATEMENT_stop);
          scan_();
          result = EXPRESSION();
           global_cast(symbol_lookup_key(global, &name, NULL))->i = result; 
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_STATEMENT_1 */
     printf("%d\n", result); 
    scan_test(NULL, RDP_T_21 /* ; */, &STATEMENT_stop);
    scan_();
    scan_test_set(NULL, &STATEMENT_stop, &STATEMENT_stop);
   }
  return result;
}

static int SUM(void)
{
  int result;
  int val;
  {
    result = PROD();
    if (scan_test_set(NULL, &rdp_SUM_2_first, NULL))
    { /* Start of rdp_SUM_2 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_19 /* + */, NULL))
          {
            scan_test(NULL, RDP_T_19 /* + */, &SUM_stop);
            scan_();
            val = PROD();
             result += val; 
          }
          else
          if (scan_test(NULL, RDP_T_20 /* - */, NULL))
          {
            scan_test(NULL, RDP_T_20 /* - */, &SUM_stop);
            scan_();
            val = PROD();
             result -= val; 
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

void TRANSLATION_UNIT(void)
{
  {
    if (scan_test_set(NULL, &rdp_TRANSLATION_UNIT_2_first, NULL))
    { /* Start of rdp_TRANSLATION_UNIT_2 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_int, NULL))
          {
            DECLARATION();
          }
          else
          if (scan_test(NULL, SCAN_P_ID, NULL))
          {
            STATEMENT();
          }
          else
            scan_test_set(NULL, &rdp_TRANSLATION_UNIT_2_first, &TRANSLATION_UNIT_stop)          ;
          }
        if (!scan_test_set(NULL, &rdp_TRANSLATION_UNIT_2_first, NULL)) break;
      }
    } /* end of rdp_TRANSLATION_UNIT_2 */
    scan_test_set(NULL, &TRANSLATION_UNIT_stop, &TRANSLATION_UNIT_stop);
   }
}

static void TYPE_SPECIFIER(void)
{
  {
    scan_test(NULL, RDP_T_int, &TYPE_SPECIFIER_stop);
    scan_();
    scan_test_set(NULL, &TYPE_SPECIFIER_stop, &TYPE_SPECIFIER_stop);
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

  arg_message("rdparser\n" RDP_STAMP "\n\n""Usage: expr [options] source");

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

    TRANSLATION_UNIT();            /* call parser at top level */
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

/* End of expr.c */
