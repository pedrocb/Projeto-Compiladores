#include "tree.h"
void print_type(type type);
void print_symbol(symbol symbol_);
void print_table(table table_);
void print_tables();
int strlit_len(char*);
void print_n_arguments_error(char *function,int n_arguments,int n_parameters, int line, int col);
void print_void_error();
void print_unknown_symbol(char *symbol, int line, int col);
void print_not_function_error(char *symbol,int line,int col);
void print_already_defined_error(char *symbol, int line, int col);
void print_lvalue_error(int line,int col);
void error_operator_type(node n, type t);
void error_operator_types(node n, type t1, type t2);
int compare_types(type type_1, type type_2);
void error_conflicting_types(type t1, type t2, int line, int col);
