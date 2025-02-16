#include <stdio.h>
#include <fcntl.h>
int main()
{
	printf("Este proceso debe de estar en estado D, esperando datos");

	int d = open("/deb/random", O_RDONLY);
	char buffer[20];

	read(d, buffer, 20); //vamos a bloquear el estado para bloquear datos
	close(d);
	printf("simulacion de lectura de archivo completado\n");
