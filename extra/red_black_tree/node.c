#include <stdlib.h>
#include "node.h"

Node* new_Node(int data)
{
	Node *new_node = (Node*) malloc(sizeof Node);
	
	new_node->data = data;
	new_node->color = 0;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

void delete_node(Node *node)
{
	free(node);
}
