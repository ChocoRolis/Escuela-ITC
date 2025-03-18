#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

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
