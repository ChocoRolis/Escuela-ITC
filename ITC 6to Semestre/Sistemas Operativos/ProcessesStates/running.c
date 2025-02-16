#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main()
{
	printf("El proceso esta en estado de ejecucion R\n");

	while (1)
	{
		volatile double resultado = 0;
		for (int i = 0; i < 1500000; ++i)
		{
			resultado += sin(i) * cos(i);
		}
	}
}
