#include"tree.h"

//Estrutura para o tipo de um simbolo. Facilita porque já nao temos que trabalhar com strings
typedef struct type_{ 
    int pointers;
    char *type;
    struct type_ *param; // Caso seja um tipo de uma função os parametros são guardados numa lista de tipos
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
}*table;


void handle_tree(node tree);
table create_table(char *name);
void add_symbol(table table_,char *name, type type_, int param);
void add_predefined_functions(table table_);
type build_type_list(node no);

void print_tables();
void print_table(table table_);
void print_symbol(symbol symbol_);

table symbol_tables;
table current_table;
