#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void stop_trapper(int sig)
{
        write(STDOUT_FILENO, "proceso detenido...\n", 20);
	pause();
}

void cont_trapper(int sig)
{
        write(STDOUT_FILENO, "proceso reanudado...\n", 21);
}

int main()
{
	int num = 0;

        signal(SIGTSTP, stop_trapper);
	signal(SIGCONT, cont_trapper);

        printf("Detenme y luego despiertame, pid: %d\n", getpid());

        while (1)
        {
		printf("%d ", num++);
		fflush(stdout);
		sleep(1);
        }
}
