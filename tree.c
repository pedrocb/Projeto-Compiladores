#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "tree.h"

void print_tree(node n, int depth){
	for(int i = 0; i < depth; i++)
		printf("..");
	if(n->value != NULL){
	    printf("%s(%s)\n", n->label,n->value);
	}
	else{
	    printf("%s\n", n->label);
	}
	if(n->child != NULL)
		print_tree(n->child, depth + 1);
	if(n->brother != NULL)
		print_tree(n->brother, depth);
}

node add_to_tree(char *label, char *value, int n_children, ...){
  va_list args;
  va_start(args, n_children);

  //create_node
  node n;
  n = (node)malloc(sizeof(struct node_));
  n->label = strdup(label);
  if(value == NULL){
      n->value = value;
  }
  else{
      n->value = strdup(value);
  }

  //add first child
  if(n_children < 1)
    return n;
  n->child = va_arg(args, node);

  //add brothers
  if(n_children > 1){
    node t = n->child;
    for(int i = 1; i < n_children; i++){
      t->brother = va_arg(args, node);
      t = t->brother;
    }
  }

  va_end(args);
  return n;
}
