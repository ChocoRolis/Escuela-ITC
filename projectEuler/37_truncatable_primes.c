#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX 1000000

bool primes[ MAX ];

void sieve(bool *nums, int size)
{
	int root = sqrt(size);
	int cont = 0;

	memset(nums, true, sizeof(bool) * size);

	nums[ 0 ] = false;
	nums[ 1 ] = false;

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

bool left_trunc(int num)
{
	if (num == 0) { return 1; }
	if (!primes[ num ]) { return 0; } 

	return left_trunc(num / 10);
}

bool right_trunc(int num, int digits)
{
	if (num == 0) { return 1; }
	if (!primes[ num ]) { return 0; } 

	num %= (int) pow(10, --digits);

	return right_trunc(num, digits);
}


int main()
{
	int cont = 0;
	int digi_cont = 90, digits = 2;

	sieve( primes, MAX );


	for (int i = 10; i < MAX; ++i)
	{
		if (digi_cont == 0)
		{
			digi_cont = i*10 - i - 1;
			++digits;
		}
		else
		{
			--digi_cont;
		}

		if (!left_trunc( i )) { continue; }
		if (!right_trunc( i, digits )) { continue; }

		cont += i;
	}
	printf("%d\n", cont);
}
