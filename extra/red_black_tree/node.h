#ifndef NODE_H
#define NODE_H

typedef struct node {
	int data;
	int color; // Red: 0, Black: 1
	struct node *parent;
	struct node *left;
	struct node *right;
} Node;

Node* new_Node(int data);
void delete_Node(Node *node);

#endif
