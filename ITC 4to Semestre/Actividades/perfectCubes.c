#include <stdio.h>
#include <time.h>

int main() {
    

	clock_t start, end;
    start = clock();	


    for (int a = 6; a <= 1000; a++) {
        for (int b = 2; b <= a; b++) {
            for (int c = b; c <= a; c++) {
                for (int d = c; d <= a; d++) {
                    if (a * a * a == b * b * b + c * c * c + d * d * d) 
		    {
			printf("Cube = %d. Triple = (%d, %d, %d)\n", a, b, c, d);
                    }
                }
            }
        }
    }

	end = clock();
    printf("Tiempo CPU: %.3f segundos\n", (double)(end - start) / 1000000);


    return 0;
}
