/*  
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <stdio.h>
#include <time.h>

int main(){
    clock_t start, end;
    double execution_time;
    start = clock(); 
    
    int num = 0, i = 0;
    while ((i * 5) <= 999){
        num += 5 * i;
        
        i++;
    }
    i = 0;

    while ((i * 3) <= 999){
        if ((i * 3) % 5 != 0){
            num += 3 * i;
        }
        i++;
    }
    printf("Restulado: %d", num);

    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\n%f", execution_time);
}

/*
    Programa más eficiente:

    int count = 0;
    for (int i = 1; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0) count += i;
    }
    printf("%d\n", count);
*/