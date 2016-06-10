#include "generator.h"

int cur_register;

void store_val(char *t, int a, char *b){
  printf("store %s %d, %s* %%%s\n", t, a, t, b);
}
void store_register(char *t, char *a, char *b){
  printf("store %s %%%s, %s* %%%s\n", t, a, t, b);
}

int get_register(table t, char *id){
  int r = 0;
  for(symbol s = t->first; s != NULL; s = s->next){
    if(s->param != 0){
      r++;
      if(strcmp(s->name, id) != 0)
        return r;
    }
  }
  return 0;
}

char *get_register_from_table(char *function_id){
  symbol symbol_ = get_symbol(current_table, function_id);
  char *aux = "";
  if(symbol_ == NULL){
    aux = append_strings("@",function_id);
  }
  else{
    if(symbol_->param == 1){
      char param_pos[5];
      sprintf(param_pos,"%d",get_register(current_table, function_id));
      aux = append_strings("%", param_pos);
    }
    else{
      aux = append_strings("%",function_id);
    }
  }
  return aux;
}

void gen_store(node n){
  printf("store ");
  print_type_llvm(n->child->type_);
  printf(" %s, ",n->child->brother->reg);
  print_type_llvm(n->child->type_);
  if(n->child->reg == NULL){
    n->child->reg = get_register_from_table(n->child->value);
  }
  printf("* %s\n", n->child->reg); //TODO: Não sei como fazer o utlimo argumento
  n->reg = n->child->brother->reg;
}

void gen_funcbody(table t, node current_node){
  cur_register=1;
  //Param alloc
  for(symbol s = t->first; s != NULL; s = s->next){
    if(s->param != 0){
      printf("%%%d = alloca ", cur_register++);
      print_type_llvm(s->type_);
      printf("\n");
    }
  }
  
  //Var alloc
  for(symbol s = t->first; s != NULL; s = s->next){
    if(s->param == 0 && strcmp(s->name, "return") != 0){
      printf("%%%s = alloca ", s->name);
      print_type_llvm(s->type_);
      printf("\n");
    }
  }
  
  //Param Store
  cur_register=1;
  for(symbol s = t->first; s != NULL; s = s->next){
    if(s->param != 0){
      printf("store ");
      print_type_llvm(s->type_);
      printf(" %%%s, ", s->name);

      s->type_->pointers++;
      print_type_llvm(s->type_);
      s->type_->pointers--;
      printf(" %%%d\n", cur_register++);
    }
  }
  
  //Body
  node n = current_node->child;
  while(strcmp(n->label,"Declaration") == 0){
    n = n->brother;
  }
  
  gen_statements(n);
}

void gen_statements(node current_node){
  for(node n = current_node; n != NULL; n = n->brother){
    if(strcmp(n->label, "Store") == 0){
      gen_statements(n->child->brother); //lado esquerdo do store não interessa aprofundar
      gen_store(n);
    }
    if(strcmp(n->label, "Return") == 0)
      printf("ret %s %d\n", "i32", 0);
    if(strcmp(n->label, "Call") == 0){
      gen_statements(n->child);
      gen_call(n);
    }
    if(strcmp(n->label, "Id") == 0)
      gen_id(n);
    if(strcmp(n->label, "ChrLit") == 0){
      n->reg = (char *)malloc(5);
      sprintf(n->reg,"%d",(int)n->value[1]);
    }
    if(strcmp(n->label, "StrLit") == 0)
      n->reg = "Aquela cena toda";
    if(strcmp(n->label, "IntLit") == 0)
      n->reg = n->value;
  }
}

void gen_id(node n){
  printf("%%%d = load ",cur_register++);
  char *reg;
  n->type_->pointers++;
  print_type_llvm(n->type_);
  n->type_->pointers--;
  reg = get_register_from_table(n->value);
  printf(" %s\n",reg);
  n->reg = (char *)malloc(5);
  sprintf(n->reg,"%%%d",cur_register-1);
}

void gen_call(node call_node){
  printf("call ");
  table function_table = get_table(call_node->child->value);
  print_type_llvm(function_table->first->type_);
  printf(" @%s(",call_node->child->value);
}

void gen_funcdef(node current_node){

  //Type
  char* l = current_node->child->label;
  printf("define ");
  
  //Pointers
  current_node = current_node->child->brother;
  int pointers = 0;
  while (strcmp(current_node->label, "Pointer") == 0) {
    current_node = current_node->brother;
    pointers++;
  }
  type aux_type = new_type(pointers,l,NULL);
  print_type_llvm(aux_type);
  free(aux_type);
  
  //ID
  char* id = current_node->value;
  current_table = get_table(id);
  printf(" @%s(", id);

  //Params
  current_node = current_node->brother;

  table t;
  for(t = symbol_tables; t != NULL; t = t->next){
    if(strcmp(t->name, id) == 0)
      break;
  }

  int first = 0;
  for(symbol s = t->first; s != NULL; s = s->next){
    if(s->param != 0){
      if(first != 0) printf(", ");
      else first = 1;

      print_type_llvm(s->type_);

      printf(" %%%s", s->name);

    }
  }


  printf(") {\n");

  //Body
  gen_funcbody(t, current_node->brother);
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
        printf("[%d x ",s->type_->array);
	print_type_llvm(s->type_);

        for(int i = 0; i < s->type_->pointers; i++)
          printf("*");

        printf("] zeroinitializer\n");
      }
      else{
	print_type_llvm(s->type_);
	
        if(s->type_->pointers > 0) printf(" null\n");
        else printf(" 0\n");
      }
    }
  }
}
