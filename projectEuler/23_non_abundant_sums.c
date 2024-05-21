#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX 28123

int divisors(int num)
{
	if (num == 1) { return 0; }

	int cont = 1;
	int step = 1;
	int i = 2;
	int root = sqrt(num);

	if (root * root == num) { cont -= root; }
	if (num & 1) { step = 2; i = 3; }

	while (i <= root)
	{
		if (num % i == 0)
		{
			cont += i + (num / i);
		}

		i += step;
	}
			
	return cont;
}

int main()
{
	bool is_num_repeated[ MAX ] = {};
	int abundant_nums[ MAX ];
	int size_arr = 0;

	int sum = (MAX * (MAX + 1)) / 2;

	for (int i = 1; i <= MAX; ++i)
	{
		int num = divisors(i);
		if (num > i)
		{
			abundant_nums[ size_arr++ ] = i;
		}
	}

	for (int i = 0; i < size_arr; ++i)
	{
		for (int j = i;  j < size_arr; ++j)
		{
			int tmp = abundant_nums[ i ] + abundant_nums[ j ];

			if ( tmp > MAX ) { continue; }
			if ( is_num_repeated[tmp] != false ) { continue; }

			is_num_repeated[tmp] = true; 

			sum -= tmp;
		}
	}

	printf("%d\n", sum);
}
