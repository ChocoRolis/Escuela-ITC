#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if (!pid)
	{
		printf("Proceso hijo creado, pero finalizado\n");
		exit(0);
	}
	else {
		printf("El proceso padre no reconoce al hijo...\n");
		//sleep(10);
	}
}
