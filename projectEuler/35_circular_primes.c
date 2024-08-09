#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX 1000000

void create_sieve(bool *nums, int size)
{
        int root = sqrt(size);
         
        memset(nums, true, sizeof(bool) * size);
     
        for (int i = 2; i <= root; ++i)
        {
                if (nums[ i ]) 
                { 
                        for (int j = 0; (i*i + i*j) < size; ++j)
                        {
                                nums[i*i + i*j] = false;
                        } 
                }
        }
}

bool rotations_are_prime(int num, int digits, bool *primes)
{
	int tmp;

	for (int i = 0; i < digits; ++i)
	{
		if (!primes[ num ]) { return false; }

		tmp = num % 10;
		num /= 10;
		num += tmp * pow(10, digits - 1);
	}

	return true;
}

int main()
{
	int sum = 13;
	int digits = 3;
	int digits_mask = 1e3;
	bool primes[ MAX ];

	create_sieve(primes, MAX);

	for (int i = 101; i < MAX; i += 2)
	{
		if (digits_mask / i == 0)
		{
			++digits;
			digits_mask *= 10;
		}

		if ( !rotations_are_prime(i, digits, primes) ) { continue; }

		++sum;
	}

	printf("%d\n", sum);
}
