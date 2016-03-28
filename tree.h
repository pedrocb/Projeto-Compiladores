typedef struct node_{
	char *label;
	struct node_ *child;
	struct node_ *brother;
}*node;

void print_tree(node n, int depth);
/*
node n 					-> where to start
int depth 			-> aux var for the prints ("..")
*/

node add_to_tree(char *label, int n_children, ...);
/*
char *label 		-> label to name the new node
int n_children 	-> number of aux arguments
...							-> list of (node) arguments to add as children of the new node
*/
