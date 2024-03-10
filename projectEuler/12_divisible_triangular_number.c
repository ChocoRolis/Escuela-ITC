#include <stdio.h>
#include <math.h>

int cant_divisores(int num)
{
	int cont = 0;
	for (int i = 12; i <= sqrt(num); ++i)
	{
		if (num % i == 0) cont++;
	}
	return cont;
}

int main()
{
	int i = 0;
	while (++i)
	{
		if (cant_divisores(i*(i+1) / 2) > 500)
		{
			printf("%d\n", i*(i+1) / 2);
			break;
		}
	}
}

