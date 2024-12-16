#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// Función para imprimir los elementos de la lista
void print_list(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL; // Lista inicialmente vacía

    // Prueba de push_back
    printf("Agregando elementos al final de la lista:\n");
    push_back(&head, 10);
    push_back(&head, 20);
    push_back(&head, 30);
    print_list(head); // Esperado: 10 -> 20 -> 30 -> NULL

    // Prueba de insert_node
    printf("\nInsertando elementos:\n");
    insert_node(&head, 5, 0);  // Insertar 5 en la posición 0
    insert_node(&head, 15, 2); // Insertar 15 en la posición 2
    insert_node(&head, 35, 5); // Insertar 35 en la posición 5 (final)
    print_list(head); // Esperado: 5 -> 10 -> 15 -> 20 -> 30 -> 35 -> NULL

    // Prueba de at
    printf("\nAccediendo a elementos:\n");
    printf("Elemento en posición 0: %d\n", at(&head, 0)); // Esperado: 5
    printf("Elemento en posición 3: %d\n", at(&head, 3)); // Esperado: 20
    printf("Elemento en posición 5: %d\n", at(&head, 5)); // Esperado: 35

    // Prueba de delete_node
    printf("\nEliminando elementos:\n");
    delete_node(&head, 0); // Eliminar en posición 0 (5)
    delete_node(&head, 2); // Eliminar en posición 2 (20)
    delete_node(&head, 3); // Eliminar en posición 3 (35)
    print_list(head); // Esperado: 10 -> 15 -> 30 -> NULL

    // Prueba de size
    printf("\nTamaño de la lista: %d\n", size(&head)); // Esperado: 3

    // Prueba de clear
    printf("\nEliminando toda la lista:\n");
    clear(&head);
    print_list(head); // Esperado: NULL

    return 0;
}

