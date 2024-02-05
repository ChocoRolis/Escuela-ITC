#include "stdio.h"
#include "stdlib.h"

/*Problem 1. Brazo Rob´otico
Standard input
Time limit: 3 seconds
Te han contratado para dise˜nar el software de un brazo rob´otico utilizado en procesos de manufac-
tura automatizada. Este brazo realiza operaciones secuenciales a lo largo de un eje lineal, iniciando su
actividad desde una posici´on base designada como punto p con valor igual a 0.
Las instrucciones que el brazo rob´otico puede seguir son las siguientes:
 ATRAS: Mover una unidad hacia atras, es decir, p disminuye en 1.
 ADELANTE: Mover una unidad hacia adelante, es decir, p aumenta en 1.
 IGUAL QUE i: Realizar la misma acci´on que la instrucci´on i. Puedes asumir que i es un n´umero
positivo que no supera el n´umero de instrucciones antes de esta.
Input
La entrada comienza con un entero c (0 < c ≤ 100) que indica el n´umero de casos de prueba. Cada
caso de prueba comienza con un entero t que indica el n´umero de instrucciones. Cada una de las
siguientes t l´ıneas es una instrucci´on.
Output
Para cada caso de prueba, imprime la posici´on final del brazo rob´otico. Considera que despu´es de cada
caso de prueba, el brazo regresa al origen.
Sample Input:
2
3
ADELANTE
ATRAS
IGUAL QUE 1
5
ATRAS
IGUAL QUE 1
IGUAL QUE 2
IGUAL QUE 3
IGUAL QUE 4
Sample Output:
1
-5 */


int char_a_int(char num)
{
    int ValorInt = ((int) num - 48);
    return ValorInt;
}

int main()
{
	int casos;
	
	scanf("%d", &casos);
	int resultados[casos];
	
	for (int i=0; i<casos; i++) resultados[i] = 0;

	for (int i=0; i<casos; i++)
	{
		
		int size_instrucciones;
		scanf("%d", &size_instrucciones);
		int instrucciones[size_instrucciones];
			
		char *arg = NULL;
    		size_t len = 0;
    		ssize_t leer;
		
		for (int j=0; j<size_instrucciones; j++)
		{
			leer = getline(&arg, &len, stdin);	
				


			if (arg[1] == 'D')
			{
				resultados[i] += 1;
				instrucciones[j] = 1;
			}
			else if (arg[1] == 'T')
			{
				resultados[i] += -1;
				instrucciones[j] = -1;
			}
			else if (arg[1] == 'G')
			{
				int tmp = char_a_int(arg[10]);
				printf("%s\n", arg);
				resultados[i] += instrucciones[tmp-1];
				instrucciones[j] = instrucciones[tmp-1];
			}
			
		
     	  		arg = NULL;
        		
		}
		free(arg);
	}
	
	for (int i=0; i<casos; i++)
	{
		printf("%d\n", resultados[i]);
}
	
	return 0;
}
