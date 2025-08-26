#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Este programa demuestra el uso de la memoria dinámica y las fugas 
// que puede provocar el no liberarla correctamente.
// El ejemplo muestra un arreglo de enteros con longitud SIZE el cual 
// se le reserva espacio con un malloc() y que al final del programa 
// su memoria no es liberada con free().

int main()
{
	int* arr;

	printf("Reservando memoria dinámica\n");

	arr = malloc(SIZE * sizeof(int));
	if (!arr)
	{
		fprintf(stderr, "no hay memoria suficiente\n");
		return 1;
	}

	for (int i = 0; i < SIZE; ++i)
		arr[i] = i+1;

	for (int i = 0; i < SIZE; ++i)
		printf("%d ", arr[i]);

	printf("\nliberando memoria...\n");
	
	//free()
}
