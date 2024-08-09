#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX 1000000

// no

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

int main()
{
	bool primes[ MAX ];
	int sum = 0, max = 0;

	sieve(primes, MAX);
	
}


