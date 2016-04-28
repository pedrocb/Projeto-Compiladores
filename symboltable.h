#include "tree.h"
//Estrutura para o tipo de um simbolo. Facilita porque já nao temos que trabalhar com strings
typedef struct type_{
  int pointers;
  char *type;
  struct type_ *param; // Caso seja um tipo de uma função os parametros são guardados numa lista de tipos
  int array;
}*type;

typedef struct symbol_{
  struct symbol_ *next;
  char *name;
  type type_;
  int param; //flag para impressão
}*symbol;


typedef struct table_{
  struct table_ *next;
  symbol first;
  char *name;
  int function;
  int to_print;
}*table;


table create_table(char *name);
void add_symbol(table table_,char *name, type type_, int param);
type new_type(int pointers, char* name, type param);
table get_table(char *name);
symbol get_symbol(table table_, char *name);

table symbol_tables;
table current_table;
