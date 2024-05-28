#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define EJEMPLO 1000000 

// SIEMPRE AL FINAL HACER free() AL ARREGLO DEVUELTO!!!!!
bool* sieve(int size)
{
	bool* nums = (bool*) malloc(sizeof(bool) * size);
	int root = sqrt(size);
	int cont = 0;

	memset(nums, true, sizeof(bool) * size );

	for (int i = 2; i <= root; ++i)
	{
		if (nums[i]) 
		{ 
			for (int j = 0; (i*i + i*j) < size; ++j)
			{
				nums[i*i + i*j] = false;
			} 
		}
	}

	return nums;
}

int main()
{
	bool* primes = sieve(EJEMPLO);
	printf("%d\n", primes[999999]);

	free(primes); // <<<<--------------- No se olvide usted
}

