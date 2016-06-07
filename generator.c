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
  int i = 0;
  for(str_list s = sl; s != NULL; s = s->next, i++){
    printf("@.str");
    if(i != 0)
      printf("%d", i);

    printf(" = private unnamed_addr constant [%d x i8] ", s->real_size);
    printf(" c\"%s\\00\"\n", s->val);
  }
}
