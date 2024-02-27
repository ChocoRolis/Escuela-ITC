#include <stdio.h>

int is_palindrome(int num)
{
	int sum = 0;
  	int temp = num;

  	while (num != 0)
    	{
      		sum *= 10;
      		sum += num % 10;
      		num /= 10;
    	}

  	if (sum == temp) return 1;
  	else return 0;
}

int main()
{
	int max = 0;

	for (int i = 0; i < 999; ++i)
	{
		for (int j = i; j < 999; ++j)
		{
			if (is_palindrome(i * j))
			{
				if (i*j > max)
				{
					//printf("%d * %d = %d\n",i ,j, i*j);
					max = i * j;
				}
			}
		}
	}
	printf("%d\n", max);
	return 0;
}
