#include "symboltable.h"

table create_table(char *name){
    table new_table = (table)malloc(sizeof(struct table_));
    new_table->next = NULL;
    new_table->name = strdup(name);
    
    table last_table = symbol_tables;
    if(last_table!=NULL){
	while(last_table->next!=NULL){
	    last_table = last_table->next;
	}
	last_table->next = new_table;
    }    
    return new_table;
}

void add_symbol(table table_,char *name, char *type, int param){

    symbol new_symbol = (symbol)malloc(sizeof(struct symbol_));
    new_symbol->name = strdup(name);
    new_symbol->type = strdup(type);
    new_symbol->next = NULL;
    new_symbol->param = param;
    
    symbol last = table_->first;
    if(last!=NULL){
	while(last->next!=NULL){
	    last=last->next;
	}
	last->next = new_symbol;
    }
    else{
	table_->first = new_symbol;
    }
}

void add_predefined_functions(table table_){
    add_symbol(table_,"atoi","int(char*)",0);
    add_symbol(table_,"itoa","char*(int,char*)",0);
    add_symbol(table_,"puts","int(char*)",0);
}

void handle_tree(node current_node){
    if(strcmp(current_node->label, "FuncDefinition") == 0){
	//node aux = get_brother(current_node->child,2);
	//printf("Função %s\n",aux->value);
    }
    else{
	if(current_node->child != NULL)
	    handle_tree(current_node->child);
    }
    if(current_node->brother != NULL)
	handle_tree(current_node->brother);
}

void print_symbol(symbol symbol_){
    printf("%s\t%s\t%s\n",symbol_->name,symbol_->type,(symbol_->param==1)?"param":"");
}

void print_table(table table_){
    printf("===== %s Symbol Table =====\n",table_->name);
    symbol symbol_ = table_->first;
    while(symbol_!=NULL){
	print_symbol(symbol_);
	symbol_=symbol_->next;
    }
    printf("\n");
}

void print_tables(){
    table table_ = symbol_tables;
    while(table_!=NULL){
	print_table(table_);
	table_ = table_->next;
    }
}
