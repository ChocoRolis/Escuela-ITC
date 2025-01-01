#include <stdio.h>
#include <stdlib.h>

#ifndef NODE_H
#define NODE_H

typedef struct node {
    int val;
    struct node *next;
} Node;

Node* create_node(int val);

void delete_node(Node** node, int pos);

void push_back(Node** head, int val);

void clear(Node** head);

void insert_node(Node** head, int val, int pos);

int at(Node** head, int pos);

int size(Node** head);

Node* end(Node** head);

#endif
