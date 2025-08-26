#include <stdio.h>
#include <pthread.h>

void* thread1(void* arg)
{
	FILE* t1 = fopen("t1.log", "w");

	fclose(t1);
	return NULL;
}

void *thread2(void* arg)
{

	return NULL;
}

void *thread3(void* arg)
{

	return NULL;
}

int main()
{
	pthread_t p1, p2, p3;
	
	printf("creando threads...\n");

	pthread_create(&p1, NULL, thread1, NULL);
	pthread_create(&p2, NULL, thread2, NULL);
	pthread_create(&p3, NULL, thread3, NULL);
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);
}
