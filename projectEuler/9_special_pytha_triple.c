#include <stdio.h>
#include <math.h>

int main()
{
	int c;
	for (int i = 1; i <= 999; i++)
	{
		for (int j = i; j <= 999; j++)
		{
			c = i*i + j*j;

			if (sqrt(c) == floor(sqrt(c)))
			{
				if (sqrt(c) + i + j == 1000)
				{
					printf("%d\n", (int) sqrt(c) * i * j);
					return 0;
				}
			}
		
			
		}
	}
	return 0;
}
