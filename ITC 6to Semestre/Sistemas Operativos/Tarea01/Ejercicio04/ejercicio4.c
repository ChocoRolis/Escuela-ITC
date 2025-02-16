#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int cont = 0;

void trapper(int sig) 
{
	printf("Senial recibida %d veces\n", cont + 1);
	
	if (++cont >= 5)
		exit(0);
}

int main() 
{
	signal(SIGUSR1, trapper);
	printf("Esperando SIGUSR1... (PID: %d)\n", getpid());

	while (1) 
	{
		pause();
	}

	return 0;
}

