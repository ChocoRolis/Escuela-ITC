#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void ListAgregarNodo(Nodo* inicio, int Info){
    Nodo *nuevo, *temp = inicio;
    nuevo = crearNodo(Info);
    if (inicio == NULL){
        inicio = nuevo;
    }
    else {
        while (temp != NULL){
          temp = temp->next;
        }
    }
    temp = nuevo;
}

int main(){
    puts("Code works");
    Nodo* nodito = crearNodo(3), *otroNodo = crearNodo(88);

    printf("la info del nodo es: %d\n", nodito->info);
    borrarNodo(nodito);

    printf("la info del otro nodo es: %d\n", otroNodo->info);
    ListAgregarNodo(otroNodo, 89);
    printf("la info del segundo otro nodo es: %d", (otroNodo->next)->info);
    borrarNodo(otroNodo->next); borrarNodo(otroNodo);
}