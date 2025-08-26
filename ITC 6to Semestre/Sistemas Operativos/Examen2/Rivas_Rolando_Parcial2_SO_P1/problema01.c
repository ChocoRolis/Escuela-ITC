#include <stdio.h>

// Este programa crea intencionalmente una situación que provoque un stack overflow.
//
// Una forma de crear esta situación es mediante una recursión infinita porque
// cada llamada a cualquier función hará que el sistema operativo reserve espacio
// en el stack del programa para ejecutar sus intrucciones.

// Esta función se llama a si misma infinitas veces sin salida.
void no_way_out()
{
	no_way_out();
}

int main()
{
	printf("iniciando recursion infinita\n");
	no_way_out();
}
