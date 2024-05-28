#include <stdio.h>
#include <string.h>
#include <math.h>

int sieve(int size)
{
    int nums[size];
    int root = sqrt(size);
    int cont = 0;

    memset(nums, 1, sizeof(bool) * size );

    for (int i = 2; i <= root; ++i)
    {
        if (nums[i]) 
        { 
            for (int j = 0; (i*i + i*j) < size; ++j)
            {
                nums[i*i + i*j] = 0;
            } 
        }
    }

    for (int i = 2; i < size; ++i)
    {
        if (nums[i]) ++cont;
    }
        
    return cont;
}

int main()
{
    int primes = sieve(1000000); // Counts primes below 1000000
    printf("%d\n", primes); 	// Tested on leetcode
}
