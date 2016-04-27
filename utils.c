#include"utils.h"

void print_type(type type){
  printf("%s",type->type);
  for(int i=0;i<type->pointers;i++){
    printf("*");
  }
  if(type->array != -1){
    printf("[%d]",type->array);
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
