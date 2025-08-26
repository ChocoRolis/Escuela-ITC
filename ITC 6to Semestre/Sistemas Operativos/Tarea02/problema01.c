#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

// Global variables to store parameters
int cant_forks;
char dir[128];

void process_files(char*** dir_files, int* strings_per_fort)
{
	// hago pipes
	int pipes[cant_forks][2];


	// luego forks
	// cada fork analiza texto y pone los resultado en un archivo temporal
	// proceso padre reune todos los datos en un solo archivo
}


void read_dir(int sig) 
{
	DIR* directory = opendir(dir);
	struct dirent* file;
	char*** forks_arrays;
	int* strings_per_fork;
	int file_counter = 0, files_per_fork, files_remaining;

	if (directory == NULL)
	{
		perror("no se pudo abrir el directorio");
		exit(1);
	}

	printf("SEÑAL RECIBIDA!\n\n");
	printf("Directorio: %s\n", dir);
	printf("Forks a utilizar: %d\n", cant_forks);

	// Leo dir para ver cantidad de archivos

	while ((file = readdir(directory)) != NULL) 
	{
		if (file->d_type == DT_REG) 
		{
			file_counter++;
		}
	}

	rewinddir(directory);

	// Aparto memoria para forks

	files_per_fork = file_counter / cant_forks;
	files_remaining = file_counter % cant_forks;

	forks_arrays = malloc(cant_forks * sizeof(char**));
	strings_per_fork = malloc(cant_forks * sizeof(int));

	for (int i = 0; i < cant_forks; ++i)
	{
		strings_per_fork[i] = files_per_fork + (files_remaining-- > 0);
	}

	for (int i = 0; i < cant_forks; ++i)
	{
		forks_arrays[i] = malloc(strings_per_fork[i] * sizeof(int*));
	}


	// Leo nombres de archivos
	for (int i = 0; i < cant_forks; ++i)
	{
		for (int j = 0; j < strings_per_fork[i]; ++j)
		{
			file = readdir(directory);
			
			if (file == NULL)
			{
				fprintf(stderr, "menso, alteraste los archivos");
				exit(1);
			}

			if (file->d_type != DT_REG)
			{
				--j;
				continue;
			}

			int len = strlen(file->d_name);

			forks_arrays[i][j] = malloc((len+1) * sizeof(char));
			strncpy(forks_arrays[i][j], file->d_name, len);
			forks_arrays[i][j][len] = '\0';
		}
	}

	process_files(forks_arrays, strings_per_fork);

	// Libero memoria
	for (int i = 0; i < cant_forks; ++i)
	{
		for (int j = 0; j < strings_per_fork[i]; ++j)
		{
			printf("%s ", forks_arrays[i][j]);
			free(forks_arrays[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < cant_forks; ++i)
	{
		free(forks_arrays[i]);
	}

	free(strings_per_fork);
	free(forks_arrays);
	closedir(directory);
}

int main(int argc, char **argv) 
{
	if (argc != 3) 
	{
		fprintf(stderr, "Uso: %s <directorio> <cantidad_forks>\n", argv[0]);
		return 1;
	}

	strncpy(dir, argv[1], sizeof(dir) - 1);
	dir[sizeof(dir) - 1] = '\0';

	cant_forks = atoi(argv[2]);

	if (cant_forks <= 0) 
	{
		fprintf(stderr, "Error: cantidad_forks debe ser un entero positivo\n");
		return 1;
	}

	read_dir(0);

	/*
	   signal(SIGUSR1, read_dir);

	   while (1) 
	   {
	   sleep(1);
	   }
	   */

	return 0;
}
