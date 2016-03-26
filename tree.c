#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

node create_node(char *name){
  node n;

  n = (node)malloc(sizeof(struct node_));
  n->name = strdup(name);

  n->child = NULL;
  n->brother = NULL;

  return n;
}

void add_child(node a, node b){
	if(a->child == NULL){
		a->child = b;
	}else{

		node t = a->child;
		while(t->brother != NULL)
			t = t->brother;

		t->brother = b;
	}
}

void add_brother(node a, node b){
	a->brother = b;
}

void print_tree(node n, int depth){
	for(int i = 0; i < depth; i++)
		printf("..");
	printf("%s\n", n->name);

	if(n->child != NULL)
		print_tree(n->child, depth + 1);
	if(n->brother != NULL)
		print_tree(n->brother, depth);
}

/*
int main(){
	node a = create_node("Program");
	node b = create_node("ArrayDeclaration");
	node c = create_node("Char");
	node d = create_node("Id(buffer)");
	node e = create_node("IntLit(20)");
	node f = create_node("FuncDeclaration");
	node g = create_node("Int");
	node h = create_node("Id(main)");
	node i = create_node("ParamList");
	node j = create_node("ParamDeclaration");

	add_child(a, b);
	add_child(b, c);
	add_child(b, d);
	add_child(b, e);
	add_child(a, f);
	add_child(f, g);
	add_child(f, h);
	add_child(f, i);
	add_child(i, j);


	print_tree(a, 0);

	return 1;
}
*/

/*
gcc -o main main.c
./main
*/
