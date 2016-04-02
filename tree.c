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
	printf("Adding %s to tree\n", label);

  va_list args;
  va_start(args, n_children);

  //create_node
  node n;
  n = (node)malloc(sizeof(struct node_));
  n->label = strdup(label);
  if(value == NULL) n->value = value;
  else n->value = strdup(value);

	//
	node t;
	for(int i = 0; i < n_children; i++){
		node b = va_arg(args, node);
		if(b == NULL)
			continue;

		if(n->child == NULL){
			n->child = b;
			t = b;
		}
		else{
			add_brother(t, b);
			t = b;
		}
	}
  va_end(args);
  return n;
}

node add_brother(node a, node b){
	printf("Brothering:\n");
	if(a != NULL)
		printf("----A: %s\n",a->label);
	else
		printf("----A: NULL\n");

	if(b != NULL)
		printf("----B: %s\n",b->label);
	else
		printf("----B: NULL\n");

	//---------------------

	if(b == NULL)
		return a;
	if(a == NULL)
		return b;

	node t = a;
	while(t->brother != NULL)
		t = t->brother;

	t->brother = b;

	printf("Finished Brothering\n");
	return a;
}
