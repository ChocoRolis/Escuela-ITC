#include <stdlib.h>
#include "node.h"

Node* create_Node(int info)
{
	Node* new_node = (Node*) malloc(sizeof(Node));

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->info = info;

	return new_node;
}

void delete_Node(Node* node)
{
	free(node);
}

void list_add_value(Node **iter, int value)
{
        Node **tmp, *new_node;
        new_node = create_Node(value);

        tmp = iter;
	iter = &((*iter)->next);
        while ( (*iter) )
        {
		iter = &((*iter)->next);
                tmp = &((*tmp)->next);
        }
        *iter = new_node;

        (*iter)->next = 0;
	(*iter)->prev = *tmp;
}

void delete_list(Node **head)
{
	Node **tmp;
	while ( (*head) )
	{
		tmp = head;
		head = &((*head)->next);
		deleteNode(*tmp);
	}
}
