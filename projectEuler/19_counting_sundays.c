#include <stdio.h>
#include <stdbool.h>

// A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

int main() {
    	int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    	int año_actual = 1901; 
    	int mes_actual = 1;
	int dia_actual = 2;   
    	int cant = 0;
    	bool es_bisiesto = false;
    
    	while (año_actual < 2001)
    	{
        	if (mes_actual == 2  &&  año_actual % 4 == 0)
        	{
            		es_bisiesto = true;
        	}
        	if (dia_actual == 7) { ++cant; }

        	dia_actual += dias_mes[mes_actual - 1] - 28 + es_bisiesto;

		if ( dia_actual > 7 ) 
		{
			dia_actual -= 7;
		}

		if (mes_actual == 12) { ++año_actual; mes_actual = 0; }

		++mes_actual;
        	es_bisiesto = false;
    	}
	printf("%d\n", cant);
}
