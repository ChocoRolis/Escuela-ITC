#include <stdio.h>

int two_pointers(int *arr, int size, int val)
{
	int i = 0;
	int j = size - 1;

	while ( i != j )
	{
		if (arr[ i ] + arr[ j ] == val)
		{
			return 1;
		}
		if (arr[ i ] + arr[ j ] > val)
		{
			--j;
		}
		else
		{
			++i;
		}
	}
	
	return 0;
}

int main()
{
	int arr[] = {2, 3, 5, 8, 9, 10, 11};
	int val = 17; 
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	printf("%d\n", two_pointers(arr, arrSize, val));
}
