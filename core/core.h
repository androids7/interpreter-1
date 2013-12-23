#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core_statement.h"
#include "core_variables.h"

/* LENGTH_OP_VEC_VAL => length of 'internal_comparison_operators' values */
#define LENGTH_OP_VEC_VAL 10

/* LENGTH_OP_VEC_VAL => length of 'internal_comparison_operators' index */
#define LENGTH_OP_INDEX_VAL 7

/* define comparison operators */
#define OP_EQUAL "=="
#define OP_NON_EQUAL "!="
#define OP_LESS_THAN "<"
#define OP_GREATER_THAN ">"
#define OP_LESS_EQUAL_THAN "<="
#define OP_GREATER_EQUAL_THAN ">="

/* get decimals(ascii) of operators */
#define OP_EQUAL_INT OP_EQUAL[0]
#define OP_NON_EQUAL_INT OP_NON_EQUAL[0]
#define OP_LESS_THAN_INT OP_LESS_THAN[0]
#define OP_GREATER_THAN_INT OP_GREATER_THAN[0]
#define OP_LESS_EQUAL_THAN_INT OP_LESS_EQUAL_THAN[0]
#define OP_GREATER_EQUAL_THAN_INT OP_GREATER_EQUAL_THAN[0]

/* define control struct */
#define IF_STRUCT_CTRL "if"
#define ELSE_STRUCT_CTRL "else"
#define FOR_STRUCT_CTRL "for"
#define WHILE_STRUCT_CTRL "while"
#define DEF_STRUCT_CTRL "def"
#define RETURN_STRUCT_CTRL "return"

/* IO */
#define PRINT_ESTATEMENT "print"

/* Define token to begin and end a block of instructions. */
#define BEGIN_BLOCK "{"
#define END_BLOCK "}"

/* Define token to begin and end a block of instructions.(ascii) */
#define BEGIN_BLOCK_INT BEGIN_BLOCK[0]
#define END_BLOCK_INT END_BLOCK[0]

/* define decimals(ascii) of control struct */
#define IF_STRUCT_CTRL_INT IF_STRUCT_CTRL[0]
#define ELSE_STRUCT_CTRL_INT ELSE_STRUCT_CTRL[0]
#define FOR_STRUCT_CTRL_INT FOR_STRUCT_CTRL[0]
#define WHILE_STRUCT_CTRL_INT WHILE_STRUCT_CTRL[0]
#define DEF_STRUCT_CTRL_INT DEF_STRUCT_CTRL[0]
#define RETURN_STRUCT_CTRL_INT RETURN_STRUCT_CTRL[0]

/* define decimals of print */
#define PRINT_ESTATEMENT_INT PRINT_ESTATEMENT[0]

/* save result operator char and int */
struct result_operator
{
	int op_int;
	char* op_char_p;
} result_match_operator;

/* content of regex result */
char* content_match;

/* Result of search by variable  */
variables_t* result_var_search;

/* Controller with flags if a statement */
statement_controllers_t statement_control;

int control_begin_block;
int control_end_block;
int result_comparison;

/* Functions defined by user */
DEFINED_FUNC_T DEFINED_FUNCTION( char* function_name, char* func_attributes );

/* Checks which statement is in the script */
STATEMENT_VOID_T find_statement( char* statement_string );

/* find the comparison operator in a script line */
STATEMENT_VOID_T find_comparison_operator( char* statement_string );

/* execute comparison with our operators we know */
STATEMENT_INT_T exec_comparison_operator( int operator );

/* extract arguments to the operator */
STATEMENT_VOID_T extract_args_to_func_operator( char* statement_string, char* statement_extract );

/* */
STATEMENT_VOID_T PRINT_ESTATEMENT_F( char* statement_string );

/* Print only value of variables */
STATEMENT_VOID_T VAR_PRINT( char * var_to_print );

/* Print only strings expl.: print "hello world!"*/
STATEMENT_VOID_T STRING_PRINT( char * string_to_print );
