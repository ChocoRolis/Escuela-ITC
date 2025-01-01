#include <stdio.h>
#include "permutations.h"

int main()
{
	int arr[] = {1, 2, 3, 4};

	do {

		for (int i = 0; i < 4; ++i)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");

	} while ( next_permutation(arr, arr + 4) );
}
