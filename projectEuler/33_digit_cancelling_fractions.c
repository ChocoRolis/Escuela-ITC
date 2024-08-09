#include <stdio.h>
#include <math.h>

int one_digit_cancell(int n1, int n2)
{
	double d1, d2;
	double div = (double) n1 / n2;
	char buff1[3], buff2[3];

	sprintf(buff1, "%d", n1);
	sprintf(buff2, "%d", n2);

	if (buff1[0] == buff2[0]) {
		d1 = (double) (n1 % 10);
		d2 = (double) (n2 % 10);
		if (d1 / d2 == div)  { return 1; }
	}

	if (buff1[0] == buff2[1]) {
		d1 = (double) (n1 % 10);
		d2 = (double) (n2 / 10);
		if (d1 / d2 == div)  { return 1; }
	}

	if (buff1[1] == buff2[0]) {
		d1 = (double) (n1 / 10);
		d2 = (double) (n2 % 10);
		if (d1 / d2 == div)  { return 1; }
	}

	if (buff1[1] != '0' && buff1[1] == buff2[1]) {
		d1 = (double) (n1 / 10);
		d2 = (double) (n2 / 10);
		if (d1 / d2 == div)  { return 1; }
	}

	return 0;
}

int main()
{
	int den = 1, num = 1;

	for (int i = 10; i < 100; ++i)
	{
		for (int j = i + 1 ; j < 100; ++j)
		{
			if ( one_digit_cancell(i, j) )
			{
				num *= i;
				den *= j;	
			}
		}
	}
	printf("%d / %d\n", num, den); // Simplificar con calculadora xd
}
