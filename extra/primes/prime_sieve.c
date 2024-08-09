#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define EJEMPLO 1000000

void sieve(bool *nums, int size)
{
	int root = sqrt(size);
	int cont = 0;

	memset(nums, true, sizeof(bool) * size);

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
}

/* Ejemplo de uso
int main()
{
	bool primes[EJEMPLO];
	sieve( primes, EJEMPLO );

	for (int i = 0; i < 1000; ++i)
	{
		if (primes[i])
		{
			printf("%d ", i);
		}
	}
}
*/
