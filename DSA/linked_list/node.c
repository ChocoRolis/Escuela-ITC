#include "node.h"

Node* create_node(int val)
{
	Node* new_node = (Node*) malloc(sizeof(Node));

	new_node->next = NULL;
	new_node->val = val;

	return new_node;
}

void delete_node(Node** head, int pos)
{
	Node* tmp = *head;

	if ( tmp == NULL ) { return; }

	if (pos == 0)
	{
		*head = tmp->next;
		free(tmp);
		return;
	}

	while ( --pos && tmp->next )
	{
		tmp = tmp->next;
	}

	Node* prev = tmp;
	tmp = tmp->next;
	prev->next = tmp->next;

	free( tmp );
}

void push_back(Node** head, int val)
{
        Node** tmp, *new_node;
        new_node = create_node(val);
        tmp = head;

        while ( (*tmp) )
        {
                tmp = &((*tmp)->next);
        }
	
        *tmp = new_node;
        (*tmp)->next = 0;
}

void clear(Node** head)
{
	Node* tmp; 

	while ( *head )
	{
		tmp = *head;         
		*head = (*head)->next;

		free(tmp);            
	}
}

void insert_node(Node** head, int val, int pos)
{
	Node* new_node = create_node(val);
	Node* tmp = *head;

	if (pos == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return;
	}

	while ( --pos && tmp->next )
	{
		tmp = tmp->next;
	}

	Node* prev = tmp;
	tmp = tmp->next;
	prev->next = new_node;
	new_node->next = tmp;
}

int at(Node** head, int pos)
{
	while ( pos-- && (*head) )
	{
		head = &((*head)->next);
	}

	if ( *head == NULL )
	{
		fprintf(stderr, "Index out of bounds\n");
		exit(EXIT_FAILURE);
	}

	return (*head)->val;
}

int size(Node** head)
{
	int size = 0;

	while ( *head )
	{
		head = &((*head)->next);
		++size;
	}

	return size;
}
