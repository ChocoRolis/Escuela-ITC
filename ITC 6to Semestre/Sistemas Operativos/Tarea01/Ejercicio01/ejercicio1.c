#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void trapper()
{
	write(STDOUT_FILENO, " jajajaj\n", 9);
}

int main()
{
	signal(SIGINT, trapper);

	printf("intenta detenerme, pid: %d\n", getpid());

	while (1)
	{
		pause();
	}
}
