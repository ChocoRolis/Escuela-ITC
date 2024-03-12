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


/* OTRA SOLUCION (de carlos)
#include <stdio.h>
#include <math.h>

int is_prime(long int num, unsigned int arr[500], int limite)
{
    unsigned int i;

	for (i = 0; i <= limite; i++)	
	{
		if (num % arr[i] == 0)
		{
			return 0;
		}
	}
	return num;
}

int main()
{
    
    unsigned long numerote = 600851475143;
	unsigned int arr[90000], i;
	unsigned int sqrtnumerote;
	int mayor;
	unsigned int factor;
	arr[0] = 2;
	arr[1] = 3;
	mayor = 1;
	factor = 3;
	sqrtnumerote = sqrt(numerote);
	printf("sqrt=%u\n",sqrtnumerote);
	
	for (i = 4; i < sqrtnumerote; i++)
	{
		if ( is_prime(i, arr, mayor) )
		{
		    arr[++mayor] = i;
			if( numerote % i == 0 )
			{
			    factor = arr[mayor];
			}
		}
	}
	printf("mayor_factor=%u\n",factor);
	return 0;	
}
*/
