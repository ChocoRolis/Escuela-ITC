#include <stdio.h>
#include <math.h>

int cant_div(int num)
{
	int factors = 1, i = 2, total = 1;
	float raiz = sqrt(num);

	while (i <= raiz)
	{
		while (num % i == 0)
		{
			num /= i;
			++factors;
		}
		total *= factors;
		factors = 1;
		++i;
	}

	return total;	
}

int main()
{
	int i = 1, triangular_num;
	
	do {
		triangular_num = i*(i+1) / 2;
		++i;
	} while ( cant_div(triangular_num) <= 500 );

	printf("%d\n", triangular_num);
}

