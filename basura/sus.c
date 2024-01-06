#include <stdio.h>
int main(){
    int sus = 0, num;
    char bucle;

    for (int i = 1; i < 11; i++){
        printf("%d. ", i);
        scanf("%d", &num);
        if (i % 2 == 0){
            sus += 5 - num;
            printf("(%d) ", sus);
        }
        else {
            sus += num - 1;
            printf("(%d) ", sus);
        }
    }
    printf("Resultado: %f\n", sus*2.5);
    printf("Este es un cambio");
}