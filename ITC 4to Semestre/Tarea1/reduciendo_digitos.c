/*Problema 2. Reduciendo D´ıgitos
Standard Input
Time limit: 3 seconds
Considera una funci´on f (n) dise˜nada espec´ıficamente para calcular la suma de los d´ıgitos de un
n´umero entero positivo n. Este proceso implica la descomposici´on de n en sus d´ıgitos constituyentes y
sumarlos. Un aspecto interesante de esta operaci´on es que, al aplicar f (n) sucesivamente a su propio
resultado —esto es, ejecutando f (n), luego f (f (n)), y continuando en esta secuencia con f (f (f (n))) y
as´ı sucesivamente— eventualmente el proceso termina en un n´umero de un solo d´ıgito.
Por ejemplo, sea n = 1234567891. Entonces:
f (n) = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 1 = 46
f (f (n)) = 4 + 6 = 10
f (f (f (n))) = 1 + 0 = 1 ← Un solo d´ıgito
Input
Cada l´ınea de entrada contiene un solo n´umero entero positivo n (0 < n ≤ 10100). La entrada termina
cuando n = 0, el cual no debe ser procesado.
Output
Para cada n´umero, tienes imprime una sola l´ınea con el n´umero de un solo d´ıgito obtenido despu´es de
aplicar consecutivamente f (n).
Sample Input
7
55
1234567891
123456789012345678901234567890
0
Sample Output
7
1
1
9
*/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* create_Node(int data)
{
	Node *new_node;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void delete_Node(Node *node)
{
	free(node);
}

void list_add_value(Node **head, int value)
{
	Node **tmp, *new_node;
	new_node = create_Node(value);
	tmp = head;
	while ( (*tmp) )
	{
		tmp = &((*tmp)->next);
	}
	*tmp = new_node;
    	(*tmp)->next = 0;
}

int main()
{
    Node *linked_list;
    linked_list = 0;
    list_add_value(&linked_list, NULL);
    list_add_value(&linked_list, NULL);

    printf("la info del nodo es: %d\n", linked_list->data);
    printf("la info del nodo es: %d\n", linked_list->next->data);
	
    free(linked_list->next);
    free(linked_list);


	

    return 0;
}
