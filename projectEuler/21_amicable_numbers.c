#include <stdio.h> 

int suma_divisores(int num)
{
	int cont = 0;
	for (int i = 1; i <= num / 2; ++i)
	{
		if (num % i == 0)
		{
			cont += i;
		}
	}
	return cont;
}

int main()
{
	int sum = 0;
	int num1, num2;
	int resultados[10000] = {};

	for (int i = 1; i < 10000; ++i)
	{
		if (resultados[ i ])
		{
			continue;
		}
		
		num1 = suma_divisores( i );
		resultados[ i ] = 1;

		if (num1 <= 10000 && i != num1)
		{
			num2 = suma_divisores( num1 );
			resultados[ num1 ] = 1;
			
			if (i == num2)
			{
				sum += i + num1;
			}
		}
	}
	printf("%d\n", sum);
}

