#include "stdio.h"
#include "unistd.h"


void funcionEjemplo() {
    printf("Segmento de texto \n");
}

int main() {
    printf("DirecciÃ³n de main(): %p\n", (void*) main);  
    printf("DirecciÃ³n de funcionEjemplo(): %p\n", (void*) funcionEjemplo); 
    
    while (1) { 
        sleep(5);
    }

    return 0;
}
