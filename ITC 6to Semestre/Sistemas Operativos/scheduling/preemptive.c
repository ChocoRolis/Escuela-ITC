#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 2

void *funcion_thread(void* arg)
{
	int tid = *(int*) arg;
	
	printf("Thread %d iniciando\n", tid);
	for (int i = 0; i < 5; ++i)
	{
		printf("Thread %d se está ejecutando\n", tid);
		sleep(1);
	}

	printf("ya acabaste %d\n", tid);
	pthread_exit(NULL);
}

int main()
{
	int ids[NTHREADS];
	pthread_t threads[NTHREADS];
	int codigo;

	for (int i = 0;i < NTHREADS; ++i)
	{
		ids[i] = i;
		codigo = pthread_create(&threads[i], NULL, funcion_thread, (void*)&ids[i]);

		if (codigo)
		{
			fprintf(stderr, "error: el código obtenido del pthread_create es: %d\n", codigo);
			return 1;
		}
	}

	for (int i = 0;i < NTHREADS; ++i)
	{
		ids[i] = i;
		codigo = pthread_join(threads[i], NULL);

		if (codigo)
		{
			fprintf(stderr, "error: el código obtenido del pthread_create es: %d\n", codigo);
			return 1;
		}
	} 
}
