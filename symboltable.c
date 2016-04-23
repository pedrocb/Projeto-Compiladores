#include "symboltable.h"

void handle_tree(node current_node){
    if(strcmp(current_node->label, "FuncDefinition") == 0){
	node aux = current_node->child;
	for(int i=0;i<1;i++){
	    aux = aux->brother;
	}
	printf("Função %s\n",aux->value);
    }
    else{
    }
    if(current_node->child != NULL)
	handle_tree(current_node->child);
    if(current_node->brother != NULL)
	handle_tree(current_node->brother);

}
