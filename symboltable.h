#include"tree.h"

/*typedef struct type_{
    int pointers;
    char *type;
    }type;*/

typedef struct symbol_{
    struct symbol_ *next;
    char *name;
    char * type;
    int param;
}*symbol;

typedef struct table_{
    struct table_ *next;
    symbol first;
    char *name;
}*table;


void handle_tree(node tree);
table create_table(char *name);
void add_symbol(table table_,char *name, char *type, int param);
void add_predefined_functions(table table_);

void print_tables();
void print_table(table table_);
void print_symbol(symbol symbol_);
table symbol_tables;
