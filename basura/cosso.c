#include <stdio.h>
int main()
{
	int a = 0., b = 128, t = 0, M, respuesta;

	printf("Piensa en un numero entre el 0 y 128\n");

	paso_d:
		
		M = (a + b) / 2;
		++t;
		
		printf("El numero %d es el que pensaste? ", M);
		scanf("%d", &respuesta);

		if (respuesta)
		{
			printf("El número que pensaste es %d y lo adivinaste en %d intentos\n", M, t);
			return 0;
		}

		if (t == 6)
		{
			printf("Lamento que no hayas podido adivinarlo luego de 6 intentos\n"); 
			return 0;
		}

		printf("El numero entonces es mayor? ");
		scanf("%d", &respuesta);

		if (respuesta)
		{
			a = M;
			goto paso_d;
		}

		b = M;
		goto paso_d;
}
