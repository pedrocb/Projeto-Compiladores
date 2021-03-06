#include "utils.h"



void print_type_llvm(type in){
  if(strcmp(in->type, "Int") == 0 || strcmp(in->type, "int") == 0){
    printf("i32");
  }
  else if((strcmp(in->type, "Void") == 0 || strcmp(in->type, "void") == 0) && in->pointers == 0){
    printf("void");
  }
  else{
    printf("i8");
  }
  int pointers = (in->array == -1)?in->pointers:in->pointers+1;
  for(int i=0;i<pointers;i++){
    printf("*");
  }
}

int power(int a, int b){
  int t = 1;
  for(int i = 0; i < b; i++)
    t = t * a;
  return t;
}

int octal_decimal(int n){
    int decimal=0, i=0, rem;
    while (n!=0){
        rem = n%10;
        n/=10;
        decimal += rem*power(8,i);
        ++i;
    }
    return decimal;
}

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

str_list get_string(char* str){
  for(str_list s = sl; s != NULL; s = s->next){
    if(strcmp(s->val, str) == 0)
      return s;
  }
  return NULL;
}


str_list save_string(char* str){
  str_list s;
  s = (str_list)malloc(sizeof(struct str_list_));
  s->next = NULL;
  s->val = str;
  s->size = strlen(str);

  s->llvm_format = (char*)malloc(sizeof(char) * s->size * 3);
  strcpy(s->llvm_format, "");

  //------------------------------------------------
  int max = strlen(str);
  int len = 0;

  int escape = 0;
  int nums = 0;
  int buffer = 0;

  int k = 0;

  for(int i = 1; i < max; i++){
    if(escape == 1){

      if(nums == 0){

        char t = 'x';

        if(str[i] == 'n') t = '\n';
        else if(str[i] == 't') t = '\t';
        else if(str[i] == '\'') t = '\'';
        else if(str[i] == '\"') t = '\"';
        else if(str[i] == '\\') t = '\\';

        if(t != 'x'){
          k += sprintf(k + s->llvm_format, "\\%02X", t);
          escape = 0;
          continue;
        }
      }

      if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7'){
        nums++;
        buffer = buffer * 10 + (str[i] - '0');

        if(nums != 3)
          continue;
      }
      else{
        i--;
      }

      buffer = octal_decimal(buffer);

      if(buffer > 31 && buffer < 127 && buffer != 34 && buffer != 92)
        k += sprintf(k + s->llvm_format, "%c", buffer);
      else
        k += sprintf(k + s->llvm_format, "\\%02X", buffer);

      escape = 0;
    }
    else{
      len++;
      if(str[i] == '\\'){
        //resets
        escape = 1;
        nums = 0;
        buffer = 0;
      }
      else{
        s->llvm_format[k++] = str[i];
      }
    }
  }
  s->llvm_format[k-1] = '\0';
  s->real_size = len;

  //------------------------------------------------
  if(sl == NULL){
    sl = s;
  }
  else{
    str_list t;
    for(t = sl; t->next != NULL; t = t->next);
    t->next = s;
  }
  return s;
}

char * append_strings(const char * old, const char * new)
{
  size_t len = strlen(old) + strlen(new) + 1;

    char *out = malloc(len);

    sprintf(out, "%s%s", old, new);

    return out;
}
