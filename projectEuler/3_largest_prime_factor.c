#include <stdio.h>
#include <math.h>
/* 
 The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
 */

int is_prime(long int num)
{
	for (long int i = 3; i < sqrt(num); i = i + 2)	
	{
		if (num % i == 0)
		{
			return 0;
		}
	}
	return 1;	
}

int main()
{
	long int numerote = 600851475143;
	
	for (long int i = 3; i < numerote/3; i = i + 2)
	{
		if (numerote % i == 0)
		{
			if(is_prime(numerote/i))
			{	
				printf("%ld AAAAAAAAAAAAAAAAAAA NUMEROTEEE\n", numerote/i);
				break;
			}
		}
	}
	return 0;	
}

/* OTRA SOLUCION 
int main()
{
	long int numerote = 600851475143, div = 2;

	while (numerote / div != 1)
	{
		while (numerote % div == 0)
		{
			numerote = numerote / div;
		}
		div++;
	}
	printf("%ld\n", numerote);
	return 0; 
}
*/

