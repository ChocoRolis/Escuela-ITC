#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
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
	unsigned long int sum = 2;
	for (int i = 3; i < 2000000; i = i + 2)
	{
		if (is_prime(i))
		{
			sum += i;
			//printf("%d\n", i);
		}
	}
	printf("%ld\n", sum);
	return 0;
}
