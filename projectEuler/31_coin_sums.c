#include <stdio.h>

int coin_types[] = {1, 2, 5, 10, 20, 50, 100, 200};
const int size = 8;

int coins(int sum)
{
	if (sum == 10)
	{
		return 1;
	}
	if (sum > 10)
	{
		return 0;
	}

	int tmp = 0;
	for (int i = 0; i < size; ++i)
	{
		tmp += coins(sum + coin_types[i]);
	}

	return sum + tmp;
}

int main()
{
	printf("%d\n", coins(0));
}
