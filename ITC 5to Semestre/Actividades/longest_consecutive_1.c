#include <stdio.h>

int Max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int n, max = 0, cont = 0;
	scanf("%d", &n);

	for (int i = 0; i < 32; ++i)
	{
		if (n & 1) 
		{
			++cont;
		}
		else
		{
			cont = 0;
		}

		max = Max(max, cont);
		n << 1;
	}

	printf("%d\n", max);
}
