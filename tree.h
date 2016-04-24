#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

typedef struct node_{
	char *label;
	struct node_ *child;
	struct node_ *brother;
	char *value;
}*node;

int toprint;
node syntax_tree;

void print_and_free(node n, int depth);
/*
node n 					-> where to start
int depth 			-> aux var for the prints ("..")
*/

node add_to_tree(char *label, char *value, int n_children, ...);
/*
char *label 		-> label to name the new node
int n_children 	-> number of aux arguments
...							-> list of (node) arguments to add as children of the new node
*/

node add_brother(node a, node b);
/*
node a					-> left node
node a					-> right node
returns left node
*/

node get_brother(node no, int position);
