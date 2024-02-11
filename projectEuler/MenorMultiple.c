/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include <stdio.h>
#include <time.h>

int main(){
    clock_t start, end;
    double execution_time;
    start = clock();

    int num = 0, cont;

    while(cont != 20){
        cont = 0;
        num++;
        for (int i = 20; i != 0; i--){
            if (num % i == 0){
                cont++;
            }
        }
    }
    printf("Restulado: %d", num);

    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\n%f", execution_time);
}

// Me quedó bien feo XD