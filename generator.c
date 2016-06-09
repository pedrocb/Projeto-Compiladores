#include "generator.h"

void gen_funcdef(node current_node){
  char* t = current_node->child->label;
  char* id = current_node->child->brother->value;
  printf("define %s @%s (", get_type(t), id);

  //Params
  current_node = current_node->child->brother->brother;


  printf(") {\n");

  //Body
  current_node = current_node->brother;
  for(node n = current_node->child; n != NULL; n = n->brother){
    printf("yop\n");
    //generate_code(n);
  }
  printf("}\n");
}


void generate_code(node current_node){
  if(current_node == NULL) return;

  if(strcmp(current_node->label, "FuncDefinition") == 0)
    gen_funcdef(current_node);



  if(current_node->child != NULL)
    generate_code(current_node->child);
  if(current_node->brother != NULL)
    generate_code(current_node->brother);

}

void generate_strings(){
  printf("@.str = private unnamed_addr constant [3 x i8] c\"%%d\\00\"\n");
  int i = 0;
  for(str_list s = sl; s != NULL; s = s->next, i++){
    printf("@.str%d", i+1);
    printf(" = private unnamed_addr constant [%d x i8] ", s->real_size);
    if(s->real_size == 1)
      printf(" zeroinitializer\n");
    else
      printf(" c\"%s\\00\"\n", s->llvm_format);
  }
}

void generate_predefined_funcs(){
  printf("declare i32 @sprintf(i8*, i8*, ...)\n");
  printf("declare i32 @puts(i8*)\n");
  printf("declare i32 @atoi(i8*)\n");
  printf("define i8* @itoa(i32 %%n, i8* %%buf){\n");
  printf("	%%1 = alloca i32\n");
  printf("	%%2 = alloca i8*\n");
  printf("	store i32 %%n, i32* %%1\n");
  printf("	store i8* %%buf, i8** %%2\n");
  printf("	%%3 = load i8** %%2\n");
  printf("	%%4 = load i32* %%1\n");
  printf("	%%5 = call i32 (i8*, i8*, ...)* @sprintf(i8* %%3, i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %%4)\n");
  printf("	%%6 = load i8** %%2\n");
  printf("	ret i8* %%6\n");
  printf("}\n");
}

void generate_global_vars(){
  for(symbol s = symbol_tables->first; s != NULL; s = s->next){
    if(s->type_->param == NULL){
      printf("@%s = common global ", s->name);

      if(s->type_->array != -1){
        printf("[%d x %s",s->type_->array, get_type(s->type_->type));

        for(int i = 0; i < s->type_->pointers; i++)
          printf("*");

        printf("] zeroinitializer\n");
      }
      else{
        printf("%s", get_type(s->type_->type));

        for(int i = 0; i < s->type_->pointers; i++)
          printf("*");

        if(s->type_->pointers > 0) printf(" null\n");
        else printf(" 0\n");
      }
    }
  }
}
