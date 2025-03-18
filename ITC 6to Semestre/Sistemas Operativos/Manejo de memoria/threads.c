#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>

pthread_t t1, t2, t3;

int variable = 10;	// data segment
int noi;		// BSS
// static int estatica; 	// BSS

void funcionEjemplo()
{
	printf("sengmento de texto\n");
}

void funcionStack()
{
	int varStack = 123666;
	printf("direccino de variable stack: %d\n", (void*) &varStack);
}

void* thread1(void* arg)
{
	volatile long long sum = 0;
	for (long long i = 0; i <= 500000000; i++)
	{
		sum = i * i;
		if (i % 10000000 == 0)
		{
			printf("Thread 1 esta calculando\n");
		}
	}
	printf("Thread 1 ah terminado sus calculos que son %lld\n", sum);
	return NULL;
}

void thread2()
{
	double producto = 1.0;
	for (int i = 0; i <= 100000; ++i)
	{
		producto *= pow(i, 1.0 / 3);
		if (i % 10000 == 0)
		{
			printf("Thread 2 esta calculando\n");
		}
	}
	printf("Thread ha termiando sus calculos que son %lf\n", producto);
	return NULL;
}

void thread3()
{
	long long a = 0, b = 1, c;
	for (int i = 2; i <= 50000000; ++i)
	{
		c = a + b; 
		a = b;
		b = c;
		if (i % 1000000 == 0)
		{
			printf("thread 3 esta calculando\n");
		}
	}
	printf("thread 3 ha termiando sus calculos que son %lld\n");
	return NULL;
}

void manejadorSIGUSR1(int sig)
{
	printf("senial SIGUSR1 recibida, voy a crear 4 threads...\n");

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	pthread_create(&t3, NULL, thread3, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	
	printf("todos los threads han concluido aaa");
}

int main()
{
	signal(SIGUSR1, manejadorSIGUSR1);

	int *heapping = (int*) malloc(8687678 * sizeof(int)); // heap 
	int *heapping2 = (int*) malloc(3000 * sizeof(int));

	printf("Direccion del main %d", (void*) main);
	printf("Direccion de memoria global %d", (void*) variable);

	while (1) 
	{
		sleep(5);
	}

	free(heapping);
	free(heapping2);
}	
