typedef struct node_{
	char *label;
	struct node_ *child;
	struct node_ *brother;
}*node;

void print_tree(node n, int depth);
node add_to_tree(char *label, int n_children, ...);
