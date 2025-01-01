#include <stdio.h>

#define MAX 21

void sieve(int *nums, int size)
{
	for (int i = 2; i < size; ++i)
	{
		if (nums[ i ]) { continue; }

		for (int j = i*2; j <= size; j += i)
		{
			nums[ j ] = i;
		}
	}
}

int main()
{
	int primes[ MAX ] = { 0 };
	sieve( primes, MAX );

	for (int i = 2; i < MAX; ++i)
	{
		printf("%d ", primes[ i ]);
	}
	printf("\n");
}
