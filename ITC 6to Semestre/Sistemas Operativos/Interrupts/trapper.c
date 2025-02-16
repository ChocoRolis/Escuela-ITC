#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void trapper(int sig)
{
	signal(sig, trapper);
	printf("Estoy recibiendo la senial: %d\n", sig);
}

int main(int argc, char **argv)
{
	for (int i = 0; i <= 64; ++i)
	{
		signal(i, trapper);
	}

	printf("El identificador de proceso es: %d\n", getpid());
	pause();

	printf("Senial recibida... terminando.");

	//getpid() returns the PID of the program that is being executed currently.
}
