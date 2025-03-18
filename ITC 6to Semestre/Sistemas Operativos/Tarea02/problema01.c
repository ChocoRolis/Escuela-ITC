#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>

void make_processes(int sig)
{
	DIR* dir; 
	const int cant_forks;
	char dirname[128];

	printf("Señal recibida!\n Escriba el nombre del directorio con lo archivos .txt a analizar.\n");
	scanf("%s", dir);
	printf("Cuantos forks desea que se utilizen para la operacion? ");
	scanf("%d", &cant_forks);

	int pipefd[ cant_forks ][ 2 ];
	
}

int main()
{
	signal(SIGUSR1, make_processes);

	while (1)
	{
		sleep(1);
	}
}	
