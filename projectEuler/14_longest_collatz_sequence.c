#include <stdio.h>

int main()
{
	unsigned int chain = 0, num, max = 0, max_result;

	for (int i = 999999; i > 0; --i)
	{
		num = i;
		while (num != 1)
		{
			if (num % 2 == 0)
			{
				num /= 2;
				++chain;
			}
			else
			{
				num = 3*num + 1;
				++chain;
			}
		}

		++chain;
		
		if (chain > max) 
		{
			max = chain;
			max_result = i;
		}

		chain = 0;
	}

	printf("%u\n", max_result);
	return 0;
}
