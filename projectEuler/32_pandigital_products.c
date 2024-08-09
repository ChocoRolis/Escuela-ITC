#include <stdio.h>

int is_pandigital(int i, int j, int k)
{
	int digits[10] = {};
	int nums[] = {i, j, k};

	for (int index = 0; index < 3; ++index)
	{
		while (nums[ index ])
		{
			digits[ nums[index] % 10 ] += 1;
			nums[ index ] /= 10;
		}
	}

	for (int a = 1; a < 10; ++a)
	{
		if ( digits[a] != 1 ) { return 0; }
	}

	return 1;
}

int main()
{
	int sum = 0;
	int dp[10000] = {};

	int multiplier = 10000;

	for (int i = 1; i < 100; ++i)
	{
		if (i == 10) { multiplier /= 10; } // Para optimizar un poquito

		for (int j = 100; j < multiplier; ++j)
		{
			for (int k = 1000; k < 10000; ++k)
			{
				if (dp[ k ]) { continue; }
				if (i * j != k) { continue; }
				if (is_pandigital(i, j, k))
				{
					dp[ k ] = 1;
					sum += k;
				}
			}
		}
	}
	printf("%d\n", sum);
}
