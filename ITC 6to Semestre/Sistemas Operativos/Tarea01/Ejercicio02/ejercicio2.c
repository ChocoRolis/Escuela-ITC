#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void trapper(int sig)
{
	write(STDOUT_FILENO, "bye\n", 4);
	//fflush(stdout);
	exit(0);
}

int main()
{
	signal(SIGTERM, trapper);

	printf("Detenme con SIGTERM, pid: %d\n", getpid());
	fflush(stdout);

	while (1)
	{
		pause();
	}
}
