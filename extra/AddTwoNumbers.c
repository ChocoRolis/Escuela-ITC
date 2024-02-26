#include <stdio.h>
#include <stdlib.h>

/* 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* create_node(int data)
{
    struct ListNode *new_node;
    new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}

void list_add_value(struct ListNode **head, int value)
{
    struct ListNode **tmp, *new_node;
    new_node = create_node(value);
    tmp = head;
    
    while ((*tmp))
    {
        tmp = &((*tmp)->next);
    }
    
    *tmp = new_node;
    (*tmp)->next = 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode **temp, *Nums;
    long int num1 = 0, num2 = 0, result, cont = 1;
    
    temp = &l1;
    while ((*temp))
    {
        num1 += (*temp)->val * cont;
        cont *= 10;
        temp = &((*temp)->next);
    }
    
    temp = &l2;
    cont = 1;
    
    while ((*temp))
    {
        num2 += (*temp)->val * cont;
        cont *= 10;
        temp = &((*temp)->next);
    }
    
    result = num1 + num2;
    Nums = create_node(result % 10);
    
    for (int i = 10; (result / i) == 0; i *= 10)
    {
        list_add_value(&Nums, result / i % 10);
    }
    
    return Nums;
}


int main()
{
    struct ListNode* L1, *L2, *LR;
    L1 = create_node(1);
    L2 = create_node(9);
    
    list_add_value(&L1, 2);
    list_add_value(&L1, 3);
    
    list_add_value(&L2, 8);
    list_add_value(&L2, 5);
    
    LR = addTwoNumbers(L1, L2);
    
    printf("%d %d %d", L1->val, L1->next->val, L2->next->next->val);
    
    free(L1);
    free(L2);
    return 0;
}



