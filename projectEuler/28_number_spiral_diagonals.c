#include <stdio.h>

int main()
{
	int sum = 1, num = 1;
	for (int i = 2; i <= 1000; i += 2)
	{
		for (int j = 0; j < 4; ++j)
		{
			num += i;
			sum += num;
		}
	}

	printf("%d\n", sum);
}
