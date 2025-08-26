#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int desc[2]; // descriptor
	char buffer[100]; // buffer
	
	if ( pipe(desc) == -1 ) // intentamos crear un pipe
	{
		perror("Error al intentar crear el pipe");
		return 1;
	}

	if ( fork() == 0 )
	{
		close( desc[0] ); // hijo no leerá nada
		write( desc[1], "contenido de comunicación", 13);
		close( desc[1] ); // hijo cierra descriptor de escritura
	}
	else 
	{
		close( desc[1] ); // padre no escribirá nada
		read( desc[0], buffer, sizeof(buffer));
		close( desc[0] ); // se cierra lectura
	}
}
