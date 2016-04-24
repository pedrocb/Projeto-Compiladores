#include "tree.h"

void print_and_free(node n, int depth){
  if(toprint == 1){
    for(int i = 0; i < depth; i++)
      printf("..");

    if(n->value != NULL) printf("%s(%s)\n", n->label,n->value);
    else printf("%s\n", n->label);
  }
  if(n->child != NULL) print_and_free(n->child, depth + 1);
  if(n->brother != NULL) print_and_free(n->brother, depth);

  free(n);
}


node add_to_tree(char *label, char *value, int n_children, ...){
  va_list args;
  va_start(args, n_children);

  //create_node
  node n;
  n = (node)malloc(sizeof(struct node_));
  n->label = strdup(label);
  if(value == NULL) n->value = value;
  else n->value = strdup(value);

  node t;
  for(int i = 0; i < n_children; i++){
    node b = va_arg(args, node);

    //Discard NULL children
    if(b == NULL)
      continue;

    //Add child
    if(n->child == NULL){
      n->child = b;
      t = b;
    }
    //Add brothers
    else{
      add_brother(t, b);
      t = b;
    }
  }

  va_end(args);
  return n;
}

node add_brother(node a, node b){
  if(b == NULL) return a;
  if(a == NULL) return b;

  node t = a;
  while(t->brother != NULL)
    t = t->brother;

  t->brother = b;

  return a;
}


node get_brother(node no, int position){
  node result = no;
  for(int i=0;i<position-1;i++){
    result = result->brother;
  }
  return result;
}
