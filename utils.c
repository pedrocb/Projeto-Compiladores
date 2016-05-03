#include "utils.h"

void print_single_type(type type){
  printf("%s",type->type);
  for(int i=0;i<type->pointers;i++){
    printf("*");
  }
  if(type->array != -1){
    printf("[%d]",type->array);
  }
}

void print_type(type type_){
  print_single_type(type_);
  type params = type_->param;
  if(params!=NULL){
    printf("(");
    print_single_type(params);
    params = params->param;
    while(params!=NULL){
      printf(",");
      print_single_type(params);
      params = params->param;
    }
    printf(")");
  }
}

void print_symbol(symbol symbol_){
  printf("%s\t",symbol_->name);
  print_type(symbol_->type_);
  printf("%s\n",(symbol_->param==1)?"\tparam":"");
}

void print_table(table table_){
  if(table_->to_print == 1){
    if(strcmp(table_->name,"Global") == 0)
      printf("===== %s Symbol Table =====\n",table_->name);
    else
      printf("===== Function %s Symbol Table =====\n",table_->name);
    symbol symbol_ = table_->first;
    while(symbol_!=NULL){
      print_symbol(symbol_);
      symbol_=symbol_->next;
    }
    printf("\n");
  }
}

void print_tables(){
  table table_ = symbol_tables;
  while(table_!=NULL){
    print_table(table_);
    table_ = table_->next;
  }
}

int strlit_len(char *str){
  int max = strlen(str);
  int len = 0;

  int escape = 0;
  int nums = 0;

  for(int i = 1; i < max; i++){
    if(escape == 1){
      if(nums == 0){
        if(str[i] == 'n' || str[i] == 't' || str[i] == '\'' || str[i] == '\"' || str[i] == '\\')
          escape = 0;
        else
          nums++;
      }
      else{
        if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7')
          nums++;
          if(nums == 3)
            escape = 0;
        else{
          escape = 0;
        }
      }
    }
    else{
      len++;
      if(str[i] == '\\')
        escape = 1;
    }
  }
  return len;
}
