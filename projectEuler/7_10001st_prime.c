#include <stdio.h>
/* By listing the first six prime numbers: 2, 3, 5, 7, 11 and 13, we can see that the 6th prime is 13.

What is the 10001st prime number? */

int is_prime(int num)
{
	for (int i = 3; i < num; i++)
	{
		if (num % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int cont = 1, i = 3;
	while (cont < 10001)
	{
		if (is_prime(i))
	       	{
			printf("%d\n", i);
			++cont;
		}
		i = i + 2;
	}
	return 0;
}
// 104743
