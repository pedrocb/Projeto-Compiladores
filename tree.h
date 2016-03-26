typedef struct node_{
	char *name;
	struct node_ *child;
	struct node_ *brother;
}*node;

node create_node(char *name);
void add_child(node a, node b);
void add_brother(node a, node b);
void print_tree(node n, int depth);
