#include <stdio.h>
#include <stdlib.h> // Para qsort
#include <float.h>  // Para FLT_MIN

// Estructura para representar un proceso
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int completed; // Bandera: 0 = no completado, 1 = completado
} Process;

// Estructura para almacenar las entradas del diagrama de Gantt
typedef struct {
    int pid;         // PID del proceso (-1 para IDLE)
    int start_time;
    int end_time;
} GanttEntry;

// Función de comparación para ordenar procesos por tiempo de llegada
int compareArrivalTimes(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->arrival_time - p2->arrival_time;
}

int main() {
    int n, i, j;
    int completed_count = 0;
    int current_time = 0;
    float total_turnaround_time = 0;
    float total_waiting_time = 0;

    printf("Ingrese la cantidad de procesos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El número de procesos debe ser positivo.\n");
        return 1;
    }

    Process proc[n];
    GanttEntry gantt[2 * n]; // Tamaño suficiente para procesos e idle times
    int gantt_count = 0;

    // --- Entrada de datos ---
    printf("\n--- Ingrese los detalles de cada proceso ---\n");
    for (i = 0; i < n; i++) {
        printf("Proceso %d:\n", i + 1);
        printf("  PID: ");
        scanf("%d", &proc[i].pid);
        printf("  Arrival Time (AT): ");
        scanf("%d", &proc[i].arrival_time);
        printf("  Burst Time (BT): ");
        scanf("%d", &proc[i].burst_time);
        proc[i].completed = 0; // Inicializar como no completado
        proc[i].completion_time = 0;
        proc[i].turnaround_time = 0;
        proc[i].waiting_time = 0;

        if (proc[i].arrival_time < 0 || proc[i].burst_time <= 0) {
             printf("Error: El tiempo de llegada debe ser >= 0 y el tiempo de ráfaga debe ser > 0.\n");
             return 1;
        }
    }

    // Ordenar procesos por tiempo de llegada (importante para iniciar la simulación)
    qsort(proc, n, sizeof(Process), compareArrivalTimes);

    // Asegurar que el tiempo inicial no sea menor que el primer tiempo de llegada
    current_time = proc[0].arrival_time;
    printf("\n--- Iniciando Simulación HRRN ---\n");
    printf("Tiempo inicial: %d\n", current_time);


    // --- Simulación HRRN ---
    while (completed_count < n) {
        int selected_idx = -1;
        float max_rr = -1.0; // Empezar con un valor muy bajo

        printf("\nEvaluando en current_time = %d\n", current_time);

        // Buscar el proceso elegible con el mayor Response Ratio
        int found_eligible = 0;
        for (i = 0; i < n; i++) {
            if (proc[i].arrival_time <= current_time && proc[i].completed == 0) {
                found_eligible = 1; // Encontramos al menos un proceso elegible
                // Calcular Tiempo de Espera Parcial (para el RR)
                int wait_time = current_time - proc[i].arrival_time;
                // Calcular Response Ratio (RR)
                float response_ratio = (float)(wait_time + proc[i].burst_time) / proc[i].burst_time;

                printf("  Proceso P%d: Llegó=%d, Ráfaga=%d, Espera Parcial=%d\n",
                       proc[i].pid, proc[i].arrival_time, proc[i].burst_time, wait_time);
                printf("    RR = (Espera Parcial + Ráfaga) / Ráfaga = (%d + %d) / %d = %.2f\n",
                       wait_time, proc[i].burst_time, proc[i].burst_time, response_ratio);

                // Si este proceso tiene un RR más alto, seleccionarlo
                if (response_ratio > max_rr) {
                    max_rr = response_ratio;
                    selected_idx = i;
                }
                // Si dos procesos tienen el mismo RR, podríamos desempatar por AT (opcional, HRRN no lo especifica estrictamente)
                // Aquí se elige el último encontrado con el max RR si son iguales.
            }
        }

        // Si no se encontró ningún proceso elegible en current_time
        if (selected_idx == -1) {
            // Avanzar el tiempo hasta la llegada del próximo proceso no completado
            int next_arrival = -1;
            int min_at = __INT_MAX__; // Valor muy grande

            for(i = 0; i < n; i++) {
                if (proc[i].completed == 0 && proc[i].arrival_time < min_at) {
                    min_at = proc[i].arrival_time;
                }
            }
             // Si el tiempo actual es menor que la próxima llegada, hay un tiempo IDLE
            if (current_time < min_at) {
                 printf("--> CPU IDLE desde %d hasta %d\n", current_time, min_at);
                 // Añadir entrada IDLE al Gantt
                 gantt[gantt_count].pid = -1; // -1 indica IDLE
                 gantt[gantt_count].start_time = current_time;
                 gantt[gantt_count].end_time = min_at;
                 gantt_count++;
                 current_time = min_at; // Saltar el tiempo hasta la próxima llegada
            } else {
                // Esto no debería ocurrir si la lógica es correcta, pero por si acaso.
                 current_time++; // Avanzar el tiempo mínimamente si algo salió mal
            }
            continue; // Volver al inicio del bucle para reevaluar en el nuevo current_time
        }

        // --- Ejecutar el proceso seleccionado ---
        printf("--> Proceso P%d SELECCIONADO (Highest RR = %.2f)\n", proc[selected_idx].pid, max_rr);

        // Registrar en Gantt
        gantt[gantt_count].pid = proc[selected_idx].pid;
        gantt[gantt_count].start_time = current_time;

        // Actualizar métricas del proceso completado
        proc[selected_idx].completion_time = current_time + proc[selected_idx].burst_time;
        proc[selected_idx].turnaround_time = proc[selected_idx].completion_time - proc[selected_idx].arrival_time;
        proc[selected_idx].waiting_time = proc[selected_idx].turnaround_time - proc[selected_idx].burst_time;
        proc[selected_idx].completed = 1;
        completed_count++;

        // Actualizar tiempo global
        current_time = proc[selected_idx].completion_time;

        // Finalizar entrada Gantt
        gantt[gantt_count].end_time = current_time;
        gantt_count++;

        printf("    Proceso P%d completado en time = %d\n", proc[selected_idx].pid, current_time);
    }

    printf("\n--- Simulación Finalizada ---\n");

    // --- Calcular promedios ---
    for (i = 0; i < n; i++) {
        total_turnaround_time += proc[i].turnaround_time;
        total_waiting_time += proc[i].waiting_time;
    }

    // --- Imprimir Tabla de Resultados ---
    printf("\n--- Tabla de Resultados Finales ---\n");
    printf("+-----+--------------+-------------+-----------------+--------------------------+------------------------+\n");
    printf("| PID | Arrival Time | Burst Time  | Completion Time | Turnaround Time (CT-AT)  | Waiting Time (TAT-BT)  |\n");
    printf("+-----+--------------+-------------+-----------------+--------------------------+------------------------+\n");
    for (i = 0; i < n; i++) {
        // Para encontrar el proceso correcto en el array original 'proc' (que fue ordenado por AT)
        // Buscamos el proceso con el PID correspondiente si el orden original importara,
        // pero como calculamos todo, podemos imprimir en el orden actual (ordenado por AT).
        // Si se quisiera el orden original de entrada, se necesitaría guardar ese orden.
        // Imprimiremos en el orden que están en el array 'proc' (ordenado por AT)
        printf("| %3d | %12d | %11d | %15d | %3d (%3d - %3d)      | %3d (%3d - %3d)       |\n",
               proc[i].pid,
               proc[i].arrival_time,
               proc[i].burst_time,
               proc[i].completion_time,
               proc[i].turnaround_time, proc[i].completion_time, proc[i].arrival_time,
               proc[i].waiting_time, proc[i].turnaround_time, proc[i].burst_time);
    }
    printf("+-----+--------------+-------------+-----------------+--------------------------+------------------------+\n");

    printf("\nPromedio Turnaround Time: %.2f\n", total_turnaround_time / n);
    printf("Promedio Waiting Time: %.2f\n", total_waiting_time / n);

    // --- Imprimir Diagrama de Gantt ---
    printf("\n--- Diagrama de Gantt ---\n");
    // Línea superior (PIDs)
    printf("|");
    for (i = 0; i < gantt_count; i++) {
        int duration = gantt[i].end_time - gantt[i].start_time;
        char label[10];
        if (gantt[i].pid == -1) {
            snprintf(label, 10, "IDLE");
        } else {
            snprintf(label, 10, " P%d ", gantt[i].pid);
        }
        // Ajustar el ancho basado en la duración (aproximado)
        int print_width = duration * 2 + 1; // Ancho simple para visualización
        if (print_width < 6) print_width = 6; // Ancho mínimo
        printf("%*s|", print_width, label); // Centrar etiqueta (aproximado)
    }
    printf("\n");

    // Línea inferior (Tiempos)
    printf("%d", gantt[0].start_time); // Tiempo inicial
    for (i = 0; i < gantt_count; i++) {
        int duration = gantt[i].end_time - gantt[i].start_time;
         int print_width = duration * 2 + 1;
         if (print_width < 6) print_width = 6;
        printf("%*d", print_width +1, gantt[i].end_time); // +1 para alinear con '|'
    }
    printf("\n");


    return 0;
}
