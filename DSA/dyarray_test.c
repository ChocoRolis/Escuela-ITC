#include <stdio.h>
#include "dyarray.h"

int main()
{
	dyarray *ptr = arr_create(4);
	printf("hello world\n");

	arr_set(ptr, 0, 8);
	arr_set(ptr, 1, 3);
	arr_set(ptr, 2, 2);
	arr_set(ptr, 3, 7);

	for (int i = 0; i < arr_size(ptr); ++i)
	{
		printf("%d ", arr_get(ptr, i));
	}
	printf("\n");

	arr_free(ptr);
}
