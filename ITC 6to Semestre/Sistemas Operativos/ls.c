#include <unistd.h>
// ejemplo de un system call para ejecutar el comando ls
int main()
{
	execve("/bin/ls",
		(char*[]){"ls", "-lh", NULL}, 
		(char*[]){NULL});
}	
