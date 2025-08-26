#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define NFIFO "pipe"

int main()
{
	int fd;
	char mensaje[] = "esto es un proceso escritor";

	mkfifo(NFIFO, 0666);

	fd = open(NFIFO, O_WRONLY);
	if (fd == -1)
}
