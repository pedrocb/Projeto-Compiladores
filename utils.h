#include "tree.h"

typedef struct str_list_{
  char *val, *llvm_format;
  int size, real_size;
  struct str_list_ *next;
  int pos;
}*str_list;

str_list sl;

void print_type_llvm(type in);
str_list save_string(char* str);
str_list get_string(char* str);

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
char * append_strings(const char * old, const char * new);
