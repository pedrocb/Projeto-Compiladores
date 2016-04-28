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

//Adiciona funções predefinidas (está no enunciado)
void add_predefined_functions(table table_){
  type atoi_type_ = new_type(0,"int",new_type(1,"char",NULL));
  type itoa_type_ = new_type(1,"char",atoi_type_);

  add_symbol(table_,"atoi",atoi_type_,0);
  add_symbol(table_,"itoa",itoa_type_,0);
  add_symbol(table_,"puts",atoi_type_,0);
}
//Percorre os parametros e adiciona tanto
type handle_param_list(node no, int flag){
  node aux = no->child; //ParamList
  type typelist = NULL;
  type current_type;
  while(aux!=NULL){ //Se existe um parameterDecl
    node var = aux->child;
    int pointers = 0;
    char *type_ = var->label;
    var = var->brother;
    while(var!= NULL && strcmp(var->label,"Id") != 0){
      pointers++;
      var = var->brother;
    }
    type type_new = new_type(pointers,type_,NULL); //Cria o tipo para a declaraçao da função na tabela global
    if(flag == 0 && var!=NULL) 
      add_symbol(current_table,var->value,new_type(pointers,type_,NULL),1); //Adiciona o simbolo a funçao,
    if(typelist == NULL){ //Se é o primeiro parametro
      typelist = type_new;
      current_type = typelist;
    }
    else{
      current_type->param = type_new; //Vai adicionando os tipos dos parametros a typelist
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
    current_table = get_table(aux->value);
    if(current_table == NULL){
      current_table = create_table(aux->value); //current table vai ter a tabela da função que estamos a tratar, para mais tarde sabermos em que tabela inserir os simbolos
      current_table->function = 1;
    }
    current_table->to_print = 1;
    add_symbol(current_table,"return", new_type(pointers,type_,NULL),0);
    type typelist = handle_param_list(aux->brother,0); //O type list vai ter os tipos dos parametros para poder criar o simbolo na tabela geral
    if(get_symbol(symbol_tables,aux->value)==NULL){
      add_symbol(symbol_tables,aux->value,new_type(pointers,type_,typelist),0); //Depois vem o id da função
    }
    handle_tree(aux->brother);
  }
  else if(strcmp(current_node->label, "FuncDeclaration") == 0){
    node aux = current_node->child;
    int pointers = 0;
    char *type_ = aux->label; //Primeiro filho é o tipo da função
    aux = aux->brother;
    while(strcmp(aux->label,"Id") != 0){ //Depois vem uma lista de ponteiros
      pointers++;
      aux = aux->brother;
    }
    current_table = get_table(aux->value);
    if(current_table == NULL){
      current_table = create_table(aux->value);
      current_table->function = 1;
      type typelist = handle_param_list(aux->brother,1); //O type list vai ter os tipos dos parametros para poder criar o simbolo na tabela geral
      if(get_symbol(symbol_tables,aux->value)==NULL){
	add_symbol(symbol_tables,aux->value,new_type(pointers,type_,typelist),0); //Depois vem o id da função
      }
      current_table = symbol_tables;
    }
    handle_tree(aux->brother);
    
  }
  else if(strcmp(current_node->label, "Declaration") == 0){
    node aux = current_node->child;
    int pointers = 0;
    char *type_ = aux->label; //Primeiro filho é o tipo da função
    aux = aux->brother;
    while(strcmp(aux->label,"Id") != 0){ //Depois vem uma lista de ponteiros
      pointers++;
      aux = aux->brother;
    }
    if(get_symbol(current_table,aux->value)==NULL){
      add_symbol(current_table,aux->value,new_type(pointers,type_,NULL),0); //Depois vem o id da função
    }
  }
  else if(strcmp(current_node->label, "ArrayDeclaration") == 0){
    node aux = current_node->child;
    int pointers = 0;
    char *type_ = aux->label; //Primeiro filho é o tipo da função
    aux = aux->brother;
    while(strcmp(aux->label,"Id") != 0){ //Depois vem uma lista de ponteiros
      pointers++;
      aux = aux->brother;
    }
    type type_new = new_type(pointers,type_,NULL);
    if(aux->brother->value[0] == '0'){
      sscanf(aux->brother->value,"%o",&type_new->array);
    }else{
      sscanf(aux->brother->value,"%d",&type_new->array);
    }
    if(get_symbol(current_table, aux->value)==NULL){
      add_symbol(current_table,aux->value,type_new,0); //Depois vem o id da função
    }
  }
  else{
    if(current_node->child != NULL)
      handle_tree(current_node->child);
  }
  if(current_node->brother != NULL)
    handle_tree(current_node->brother);
}

