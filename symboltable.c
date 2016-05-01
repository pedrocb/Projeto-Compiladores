#include "symboltable.h"

//Cria uma tabela com o nome name
table create_table(char *name){
  table table_;
  if(symbol_tables!=NULL){
    for(table_ = symbol_tables;table_->next!=NULL;table_=table_->next){
      if(strcmp(table_->next->name,name)==0){ //Caso já exista uma com o mesmo nome
        return table_->next;
      }
    }
  }
  table new_table = (table)malloc(sizeof(struct table_));
  new_table->next = NULL;
  new_table->name = strdup(name);
  new_table->function = 0;
  new_table->to_print = 0;
  new_table->first = NULL;
  if(symbol_tables!=NULL){
    table_->next = new_table; //Insere a tabela no fim da lista de tabelas
  }
  return new_table;
}

table get_table(char *name){
  for(table tab = symbol_tables;tab!=NULL;tab = tab->next){
    if(strcmp(tab->name,name) == 0){
      return tab;
    }
  }
  return NULL;
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

symbol get_symbol(table table_, char *name){
  for(symbol symb = table_->first;symb!=NULL;symb = symb->next){
    if(strcmp(symb->name,name) == 0){
      return symb;
    }
  }
  return NULL;
}

//Construtor de tipo de variavel
type new_type(int pointers, char* name, type param){
  type result = (type)malloc(sizeof(struct type_));

  result->pointers = pointers;
  char *type = strdup(name);
  for (char *p = type ; *p; ++p) *p = tolower(*p); //Para ficar tudo em minisculas (os tokens têm a primeira letra em maiusculo) Se calhar so fazer à primeira letra é suficiente
  result->type = type;
  result->param = param;
  result->array = -1;
  return result;
}
