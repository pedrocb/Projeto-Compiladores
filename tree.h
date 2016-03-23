#define MAXLEN 30

typedef struct node_{
	char *name;
	struct node_ *childs;
	struct node_ *next;
}*node;

node create_node(char *name){
  node n;

  n = (node)malloc(sizeof(struct node_));
  n->name = (char*)malloc(MAXLEN*sizeof(char));
  strcpy(name, n.name);

  n->childs = NULL;
  n->next = NULL;

  return node;
}
