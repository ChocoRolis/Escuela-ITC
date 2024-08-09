#include <stdio.h>
#include "node.h"

int main()
{
    puts("Code works");
    Nodo* nodito = crearNodo(3), *otroNodo = crearNodo(88);

    printf("la info del nodo es: %d\n", nodito->info);
    borrarNodo(nodito);

    printf("la info del otro nodo es: %d\n", otroNodo->info);
    ListAgregarNodo(otroNodo, 89);
    printf("la info del segundo otro nodo es: %d", (otroNodo->next)->info);
    borrarNodo(otroNodo->next); borrarNodo(otroNodo);
}
