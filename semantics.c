#include "semantics.h"

//Adiciona funções predefinidas (está no enunciado)
void add_predefined_functions(table table_){
  type atoi_type_ = new_type(0,"int",new_type(1,"char",NULL));
  type itoa_type_ = new_type(1,"char",atoi_type_);

  add_symbol(table_,"atoi",atoi_type_,0);
  create_table("atoi");
  add_symbol(table_,"itoa",itoa_type_,0);
  create_table("itoa");
  add_symbol(table_,"puts",atoi_type_,0);
  create_table("puts");
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

void handle_function_definition(node no){
  node aux = no->child;
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
  handle_tree(aux->brother->brother);
}

void handle_function_declaration(node no){
  node aux = no->child;
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
}

void handle_declaration(node no){
  node aux = no->child;
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

void handle_array_declaration(node no){
  node aux = no->child;
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

//Função para ir percorrendo a ast
void handle_tree(node current_node){
  if(current_node == NULL) return;
  if(strcmp(current_node->label, "Program") ==0 || strcmp(current_node->label , "FuncBody") == 0){
    handle_tree(current_node->child);
    return;
  }
  if(strcmp(current_node->label, "FuncDefinition") == 0){
    handle_function_definition(current_node);
    current_table = symbol_tables;
  }
  else if(strcmp(current_node->label, "FuncDeclaration") == 0){
    handle_function_declaration(current_node);
  }
  else if(strcmp(current_node->label, "Declaration") == 0){
    handle_declaration(current_node);
  }
  else if(strcmp(current_node->label, "ArrayDeclaration") == 0){
    handle_array_declaration(current_node);
  }
  else if(strcmp(current_node->label, "Sub") == 0){
    handle_tree(current_node->child);
    type type_1 = current_node->child->type_;
    int type_1_pointers = (type_1->array == -1)?type_1->pointers:type_1->pointers+1;
    type type_2 = current_node->child->brother->type_;
    int type_2_pointers = (type_2->array == -1)?type_2->pointers:type_2->pointers+1;
    if(type_1_pointers == 0 &&  type_2_pointers == 0){
      current_node->type_ = new_type(0,"int",NULL);
    }
    else if(type_1_pointers > 0 && type_2_pointers == 0){
      current_node->type_ = new_type(type_1_pointers,type_1->type,NULL);
    }
    else if(type_1_pointers == type_2_pointers && strcmp(type_1->type,type_2->type) == 0){
      current_node->type_ = new_type(0,"int",NULL);
    }
    else{
      current_node->type_ = new_type(0,"undef",NULL);
    }
  }
  else if(strcmp(current_node->label, "Add") == 0){
    handle_tree(current_node->child);
    type type_1 = current_node->child->type_;
    int type_1_pointers = (type_1->array == -1)?type_1->pointers:type_1->pointers+1;
    type type_2 = current_node->child->brother->type_;
    int type_2_pointers = (type_2->array == -1)?type_2->pointers:type_2->pointers+1;
    if(type_1_pointers == 0 &&  type_2_pointers == 0){
      current_node->type_ = new_type(0,"int",NULL);
    }
    else if(type_1_pointers > 0 && type_2_pointers == 0){
      current_node->type_ = new_type(type_1_pointers,type_1->type,NULL);
    }
    else if(type_1_pointers == 0 &&  type_2_pointers > 0){
      current_node->type_ = new_type(type_2_pointers,type_2->type,NULL);
    }
    else{
      current_node->type_ = new_type(0,"undef",NULL);
    }
  }
  else if(strcmp(current_node->label, "Eq") == 0 || strcmp(current_node->label, "Ne") == 0 || strcmp(current_node->label, "Lt") == 0 || strcmp(current_node->label, "Gt") == 0 || strcmp(current_node->label, "Le") == 0 || strcmp(current_node->label, "Ge") == 0){
    handle_tree(current_node->child);
    current_node->type_ = new_type(0,"int",NULL);
  }
  else if(strcmp(current_node->label, "Mul") == 0 || strcmp(current_node->label, "Div") == 0 || strcmp(current_node->label, "Mod") == 0 ){
    handle_tree(current_node->child);
    type type_1 = current_node->child->type_;
    int type_1_pointers = (type_1->array == -1)?type_1->pointers:type_1->pointers+1;
    type type_2 = current_node->child->brother->type_;
    int type_2_pointers = (type_2->array == -1)?type_2->pointers:type_2->pointers+1;
    if(type_1_pointers == 0 &&  type_2_pointers == 0){
      current_node->type_ = new_type(0,"int",NULL);
    }
    else{
      current_node->type_ = new_type(0,"undef",NULL);
    }
  }
  else if(strcmp(current_node->label, "IntLit") == 0){
    current_node->type_ = new_type(0,"int",NULL);
  }
  else if(strcmp(current_node->label, "Id") == 0){
    symbol symbol_ = get_symbol(current_table,current_node->value);
    if(symbol_ != NULL){
      current_node->type_ = symbol_->type_;
    }
    else{
      symbol_ = get_symbol(symbol_tables,current_node->value);
      if(symbol_ != NULL){
	current_node->type_ = symbol_->type_;
      }
      else{
	current_node->type_ = new_type(0,"undef",NULL);
      }
    }
  }
  else if(strcmp(current_node->label, "StrLit") == 0){
    current_node->type_ = new_type(0,"char",NULL);
    current_node->type_->array = strlen(current_node->value) - 1;
  }
  else if(strcmp(current_node->label, "ChrLit") == 0){
    current_node->type_ = new_type(0,"int",NULL);
  }
  else if(strcmp(current_node->label, "Call") == 0){
    handle_tree(current_node->child);
    current_node->type_ = new_type(current_node->child->type_->pointers,current_node->child->type_->type,NULL);
  }
  else if(strcmp(current_node->label, "Store") == 0){
    handle_tree(current_node->child);
    int pointers = (current_node->child->type_->array == -1)?current_node->child->type_->pointers:current_node->child->type_->pointers+1;
    current_node->type_ = new_type(pointers,current_node->child->type_->type,NULL);    
  }
  else if(strcmp(current_node->label, "Deref") == 0){
    handle_tree(current_node->child);
    int pointers = (current_node->child->type_->array == -1)?current_node->child->type_->pointers:current_node->child->type_->pointers+1;
    if(pointers > 0){
      current_node->type_ = new_type(pointers - 1 , current_node->child->type_->type, NULL);
    }
  }
  else if(strcmp(current_node->label, "Comma") == 0){
    handle_tree(current_node->child);
    int pointers = (current_node->child->brother->type_->array == -1)?current_node->child->brother->type_->pointers:current_node->child->brother->type_->pointers+1;
    current_node->type_ = new_type(pointers,current_node->child->brother->type_->type,NULL);
  }
  else if(strcmp(current_node->label, "Addr") == 0){
    handle_tree(current_node->child);
    if(strcmp(current_node->child->label,"IntLit") || strcmp(current_node->child->label,"ChrLit") == 0){
      int pointers = (current_node->child->type_->array == -1)?current_node->child->type_->pointers:current_node->child->type_->pointers+1;
      current_node->type_ = new_type(pointers + 1, current_node->child->type_->type, NULL);
    }
  }
  else if(strcmp(current_node->label, "Minus") == 0 || strcmp(current_node->label, "Plus") == 0 ){
    handle_tree(current_node->child);
    int pointers = (current_node->child->type_->array == -1)?current_node->child->type_->pointers:current_node->child->type_->pointers+1;
    if(pointers == 0){
      current_node->type_ = new_type(0,"int",NULL);
    }
  }
  else if(strcmp(current_node->label, "Not") == 0){
    handle_tree(current_node->child);
    current_node->type_ = new_type(0,"int",NULL);
  }
  else if(strcmp(current_node->label, "And") == 0 || strcmp(current_node->label, "Or") == 0){
    handle_tree(current_node->child);
    current_node->type_ = new_type(0,"int",NULL);
  }
  else{
    if(current_node->child != NULL){
      handle_tree(current_node->child);
    }
  }
  if(current_node->brother != NULL){
    handle_tree(current_node->brother);
  }
}
