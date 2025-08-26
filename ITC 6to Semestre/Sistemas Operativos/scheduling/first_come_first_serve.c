#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int arrival_time;
	int burst_time;
	int completition_time;
	int turnaround_time;
	int waiting_time;
} Process;

int compare_arrival_time(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;

    if (p1->arrival_time < p2->arrival_time) return -1;
    if (p1->arrival_time > p2->arrival_time) return 1;

    return 0;
}

void calcula_tiempos(Process lista_procesos[], int n)
{
	int clock = 0;
	int total_trt = 0; // total turn around time
	int total_wt = 0; // total waiting time
	
	qsort(lista_procesos, n, sizeof(Process), compare_arrival_time);
}

int main()
{
	
}
