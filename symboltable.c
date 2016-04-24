#include "symboltable.h"
//Cria uma tabela com o nome name
table create_table(char *name){
    table table_;
    for(table_ = symbol_tables;table_!=NULL;table_=table_->next){
	if(strcmp(table_->name,name)==0){
	    return table_;
	}
    }
    
    table new_table = (table)malloc(sizeof(struct table_));
    new_table->next = NULL; 
    new_table->name = strdup(name);
    
    if(table_!=NULL){
	table_->next = new_table; //Insere a tabela no fim da lista de tabelas
    }    
    return new_table;
}

//Cria e adiciona um simbolo a tabela table_
void add_symbol(table table_,char *name, type type_, int param){
    
    symbol new_symbol = (symbol)malloc(sizeof(struct symbol_));
    new_symbol->name = strdup(name);
    new_symbol->type_ = type_;
    new_symbol->next = NULL;
    new_symbol->param = param;
    
    symbol last = table_->first;
    if(last!=NULL){
	while(last->next!=NULL){
	    last=last->next;
	}
	last->next = new_symbol;  //Adiciona no fim da lista de simbolos da tabela
    }
    else{
	table_->first = new_symbol; //Caso seja o primeiro simbolo
    }
}

//Construtor de tipo de variavel
type new_type(int pointers, char* name, type param){
    type result = (type)malloc(sizeof(struct type_));
    
    result->pointers = pointers;
    char *type = strdup(name);
    for (char *p = type ; *p; ++p) *p = tolower(*p); //Para ficar tudo em minisculas (os tokens têm a primeira letra em maiusculo) Se calhar so fazer à primeira letra é suficiente
    
    result->type = type;
    result->param = param;
    
    return result;
}

//Adiciona funções predefinidas (está no enunciado)
void add_predefined_functions(table table_){
    type atoi_type_ = new_type(0,"int",new_type(1,"char",NULL));
    type itoa_type_ = new_type(1,"char",atoi_type_);
    
    add_symbol(table_,"atoi",atoi_type_,0);
    add_symbol(table_,"itoa",itoa_type_,0);
    add_symbol(table_,"puts",atoi_type_,0);
}

type handle_param_list(node no){
    node aux = no->child;
    type typelist = NULL;
    type current_type;
    while(aux!=NULL){
	node var = aux->child;
	int pointers = 0;
	char *type_ = var->label;
	var = var->brother;
	while(var!= NULL && strcmp(var->label,"Id") != 0){
	    pointers++;
	    var = var->brother;
	}
	type type_new = new_type(pointers,type_,NULL);
	if(var!=NULL)
	    add_symbol(current_table,var->value,new_type(pointers,type_,NULL),1);
	if(typelist == NULL){
	    typelist = type_new;
	    current_type = typelist;
	}
	else{
	    current_type->param = type_new;
	    current_type = current_type->param;
	}
	aux = aux->brother; 
    }
    return typelist;
}


//Função para ir percorrendo a ast
void handle_tree(node current_node){
    if(strcmp(current_node->label, "FuncDefinition") == 0){
	node aux = current_node->child;
	int pointers = 0;
	char *type_ = aux->label; //Primeiro filho é o tipo da função
	aux = aux->brother; 
	while(strcmp(aux->label,"Id") != 0){ //Depois vem uma lista de ponteiros
	    pointers++;
	    aux = aux->brother;
	}
	current_table = create_table(aux->value); //current table vai ter a tabela da função que estamos a tratar, para mais tarde sabermos em que tabela inserir os simbolos
	type typelist = handle_param_list(aux->brother);
	
	add_symbol(symbol_tables,aux->value,new_type(pointers,type_,typelist),0); //Depois vem o id da função
    }
    else{
	if(current_node->child != NULL)
	    handle_tree(current_node->child);
    }
    if(current_node->brother != NULL)
	handle_tree(current_node->brother);
}

void print_type(type type){ 
    printf("%s",type->type);
    for(int i=0;i<type->pointers;i++){
	printf("*");
    }
    
}

void print_symbol(symbol symbol_){
    printf("%s\t",symbol_->name);
    print_type(symbol_->type_);
    type params = symbol_->type_->param;
    if(params!=NULL){
	printf("(");
	print_type(params);
	params = params->param;
	while(params!=NULL){
	    printf(", ");
	    print_type(params);
	    params = params->param;
	}
	printf(")");
    }
    printf("\t%s\n",(symbol_->param==1)?"param":"");
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
