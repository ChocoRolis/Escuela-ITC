#ifndef NODE_H
#define NODE_H

typedef struct node {
    int info;
    struct node *next;
} Node ;

Node* createNode(int info);
void deleteNode(Node* node);
void list_add_value(Node **head, int value);
void delete_list(Node **head);

#endif
