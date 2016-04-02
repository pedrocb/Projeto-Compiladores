#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "tree.h"

void print_tree(node n, int depth){
	for(int i = 0; i < depth; i++)
	     printf("..");
	printf("%s\n", n->label);

	if(n->child != NULL)
		print_tree(n->child, depth + 1);
	if(n->brother != NULL)
		print_tree(n->brother, depth);
}

node add_to_tree(char *label, int n_children, ...){
  va_list args;
  va_start(args, n_children);

  //create_node
  node n;
  n = (node)malloc(sizeof(struct node_));
  n->label = strdup(label);


  //add first child
  if(n_children < 1)
    return n;
  n->child = va_arg(args, node);

  //add brothers
  if(n_children > 1){
    node t = n->child;
    for(int i = 1; i < n_children; i++){
			node b = va_arg(args, node);
			add_brother(t, b);
			t = b;
    }
  }

  va_end(args);
  return n;
}

node add_brother(node a, node b){
	node t = a;
	while(t->brother != NULL)
		t = t->brother;

	t->brother = b;
	return a;
}
