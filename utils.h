#include "tree.h"
void print_type(type type);
void print_symbol(symbol symbol_);
void print_table(table table_);
void print_tables();
int strlit_len(char*);
void print_n_arguments_error(char *function,int n_arguments,int n_parameters);
void print_void_error();
void print_unknown_symbol();
void print_not_function_error(char *symbol);
void print_already_defined_error(char *symbol);
