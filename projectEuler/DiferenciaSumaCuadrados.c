/* 
The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers
and the square of the sum is

Find the difference between the sum of the squares of the first 
one hundred natural numbers and the square of the sum.
The sum of the squares of the first ten natural numbers is,

*/

#include <stdio.h>
#include <math.h>

int main(){
    int num, n;
    printf("Este programa es un algoritmo que calcula la diferencia entre el cuadrado de la suma de los numeros del 1 a n y la suma de los cuadrados del 1 a n");
    
    printf("\nDe el valor de entrada n (Tiene que ser entero positivo): ");
    scanf("%d", &n);

    num = pow(n * (n + 1) / 2, 2) - (n * (n+1)*(2*n+1)) / 6;
    //printf("%d\n",pow(n * (n + 1) / 2, 2));
    //printf("%d",(n * (n+1)*(2*n+1)) / 6);
    printf("%d", num);
}

/*
PRUEBA #1
Abiente de la prueba: Equipo Dell, Windows 10, Lenguaje C
Datos de entrada: Entero no negativo = 100
Resultado esperado: 25164150
Resultado obtenido: 25164150

PRUEBA #2 
Ambiente de la prueba
Abiente de la prueba: Equipo Dell, Windows 10, Lenguaje C
Datos de entrada: Entero no negativo = -100
Resultado esperado: -25164150
Resultado obtenido: 24830850

*/