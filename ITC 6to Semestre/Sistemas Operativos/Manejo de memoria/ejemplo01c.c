#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t pid1, pid2, pid4;

int variable = 10;	// data segment
int noi;		// BSS
static int estatica; 	// BSS

void funcionEjemplo()
{
	printf("sengmento de texto\n");
}

void funcionStack()
{
	int varStack = 123666;
	printf("direccino de variable stack: %d\n", (void*) &varStack);
}

void hijo1()
{
	volatile long long sum = 0;
	for (long long i = 0; i <= 500000000; i++)
	{
		sum = i * i;
		if (i % 10000000 == 0)
		{
			printf("hijo 1 con pid %d esta calculando\n", getpid());
		}
	}
	printf("hijo 1 %d ha terminado sus calculos que son %lld\n", getpid(), sum);
	exit(0);
}

void hijo2()
{
	double producto = 1.0;
	for (int i = 0; i <= 100000; ++i)
	{
		producto *= pow(i, 1.0 / 3);
		if (i % 10000 == 0)
		{
			printf("hijo 2 con pid %d esta calculando\n", getpid());
		}
	}
	printf("hijo 2 %d ha terminado sus claculos que son %lf\n", getpid(), producto);
	exit(0);
}

void hijo3()
{
	long long a = 0, b = 1, c;
	for (int i = 2; i <= 50000000; ++i)
	{
		c = a + b; 
		a = b;
		b = c;
		if (i % 1000000 == 0)
		{
			printf("hijo3 con pid %d esta calculando\n", getpid());
		}
	}
	printf("hijo 3 %d ha terminado sus claculos que son %lld\n", getpid(),a);
	exit(0);
}

void manejadorSIGUSR1(int sig)
{
	printf("\n Senial SIGUSR1 recibida, void a crear 4 hijos...\n");

	for (int i = 0; i < 5; ++i)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			printf("Este es el hijo con pid: %d, su papa: %d\n", getpid(), getppid());
			exit(0);
		}
		else if (pid > 0)
		{
			printf("Proceso padre con PID: %d, creo a un hijo con PID: %d\n", getpid(), pid);
		}
		else 
		{
			perror("Error al intentar hace el fork");
			exit(1);
		}
	}
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
