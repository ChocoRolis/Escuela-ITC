#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

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

int test_coefficients(bool* primes, int a, int b)
{
	int n = 0, cont = 0;
	while ( primes[ n*n + a*n + b ] )
	{
		++n;
		++cont;
	}
	
	return cont;
}

int main()
{
	int max_quantity_of_primes = 0;
	int a, b;
	bool primes[ 1000000 ];

	sieve( primes, 1000000 );

	for (int i = -1000; i < 1000; ++i)
	{
		for (int j = 2; j <= 1000; ++j)
		{
			int tmp = test_coefficients( primes, i, j );

			if ( tmp > max_quantity_of_primes )
			{
				max_quantity_of_primes = tmp;
				a = i; 
				b = j;
			}
		}
	}

	printf("%d*%d: %d\n", a, b, a*b);
}
