#include "generator.h"

char* types[] = {"i32", "i8"};

int get_type(char* in){

  if(strcmp(in, "Int") == 0)
    return 0;

  if(strcmp(in, "Char") == 0)
    return 1;

  return 0;
}


void gen_funcdef(node current_node){
  char* t = current_node->child->label;
  char* id = current_node->child->brother->value;
  printf("define %s @%s (", types[get_type(t)], id);

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
