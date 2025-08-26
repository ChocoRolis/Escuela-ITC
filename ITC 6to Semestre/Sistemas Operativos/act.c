#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> // For INT_MIN, INT_MAX

// --- Process Structure ---
typedef struct {
    // Input fields
    int arrivalTime;
    int burstTime;
    int priority; // Higher value = higher priority

    // Generated/Calculated fields
    int pid;
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int isCompleted; // Flag: 0=not completed, 1=completed
} Process;

// --- Function Prototypes ---
void getInput(Process processes[], int n);
void generatePIDs(Process processes[], int n);
void priorityFCFS(Process processes[], int n, int executionOrder[]);
void printResults(Process processes[], int n, int executionOrder[]);
int findNextProcess(Process processes[], int n, int currentTime); // Helper to find the next process to run

// --- Main Function ---
int main() {
    // Seed random number generator ONCE
    srand(time(NULL));

    int n; // Number of processes

    printf("--------------------------------------------------\n");
    printf(" Priority FCFS Scheduler Simulation (Non-Preemptive)\n");
    printf("   (Higher Priority Number = Higher Priority)\n");
    printf("--------------------------------------------------\n");

    printf("Enter the number of processes: ");
    // Basic validation for number of processes
    while (scanf("%d", &n) != 1 || n <= 0) {
         printf("Invalid input. Please enter a positive integer for the number of processes: ");
         // Clear input buffer
         while (getchar() != '\n');
    }


    // --- Memory Allocation ---
    // Allocate memory for processes dynamically
    Process *processes = (Process *)malloc(n * sizeof(Process));
    if (processes == NULL) {
        perror("Error: Failed to allocate memory for processes");
        return 1;
    }

    // Allocate memory to store the order of execution (stores indices)
    int *executionOrder = (int *)malloc(n * sizeof(int));
    if (executionOrder == NULL) {
        perror("Error: Failed to allocate memory for execution order");
        free(processes); // Clean up previous allocation
        return 1;
    }

    // --- Input and Initialization ---
    getInput(processes, n);
    generatePIDs(processes, n);

    // Initialize calculated fields before simulation
    for (int i = 0; i < n; i++) {
        processes[i].startTime = -1;       // Not yet started
        processes[i].completionTime = -1;  // Not yet completed
        processes[i].waitingTime = -1;
        processes[i].turnaroundTime = -1;
        processes[i].isCompleted = 0;      // Mark as not completed
    }

    // --- Run Scheduler Simulation ---
    priorityFCFS(processes, n, executionOrder);

    // --- Display Results ---
    printResults(processes, n, executionOrder);

    // --- Cleanup ---
    free(processes);
    free(executionOrder);

    return 0;
}

// --- Function Implementations ---

/**
 * @brief Gets user input for Arrival Time, Burst Time, and Priority for each process.
 * @param processes Array of Process structures.
 * @param n Number of processes.
 */
void getInput(Process processes[], int n) {
    printf("\nEnter process details:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d (Arrival Time Burst_Time Priority): ", i + 1);
        // Input validation loop
        while (scanf("%d %d %d", &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority) != 3 ||
               processes[i].arrivalTime < 0 || processes[i].burstTime <= 0 || processes[i].priority < 0) {
            printf("Invalid input. Please enter non-negative Arrival Time, positive Burst Time, and non-negative Priority.\n");
            printf("Process %d (AT BT PRI): ", i + 1);
            // Clear input buffer in case of non-numeric input
            while (getchar() != '\n');
        }
    }
}

/**
 * @brief Generates unique-ish random 4-digit PIDs for each process.
 * @param processes Array of Process structures.
 * @param n Number of processes.
 */
void generatePIDs(Process processes[], int n) {
    // Simple PID generation (1000-9999)
    // Note: True uniqueness isn't guaranteed but collisions are unlikely for small N.
    // A more robust solution would involve checking for duplicates.
    for (int i = 0; i < n; i++) {
        processes[i].pid = 1000 + (rand() % 9000);
    }
}

/**
 * @brief Helper function to find the index of the next process to execute based on Priority FCFS.
 * @param processes Array of Process structures.
 * @param n Number of processes.
 * @param currentTime The current time in the simulation.
 * @return The index of the selected process, or -1 if no process is ready.
 */
int findNextProcess(Process processes[], int n, int currentTime) {
    int highestPriority = INT_MIN; // Use INT_MIN to correctly handle priority 0
    int selectedProcessIndex = -1;
    int earliestArrival = INT_MAX;

    for (int i = 0; i < n; i++) {
        // Check if the process has arrived and is not yet completed
        if (!processes[i].isCompleted && processes[i].arrivalTime <= currentTime) {
            // Check if this process has higher priority
            if (processes[i].priority > highestPriority) {
                highestPriority = processes[i].priority;
                earliestArrival = processes[i].arrivalTime;
                selectedProcessIndex = i;
            }
            // Tie-breaker: If priorities are equal, choose the one that arrived earlier (FCFS)
            else if (processes[i].priority == highestPriority) {
                if (processes[i].arrivalTime < earliestArrival) {
                    earliestArrival = processes[i].arrivalTime;
                    selectedProcessIndex = i;
                    // Note: If arrival times are also the same, the one found first (lower index i) will be kept.
                    // This is a stable tie-breaker.
                }
            }
        }
    }
    return selectedProcessIndex; // Returns -1 if no ready process was found
}

/**
 * @brief Simulates the Priority FCFS scheduling algorithm.
 * @param processes Array of Process structures (will be updated with results).
 * @param n Number of processes.
 * @param executionOrder Array to store the indices of processes in execution order.
 */
void priorityFCFS(Process processes[], int n, int executionOrder[]) {
    int currentTime = 0;
    int completedProcesses = 0;
    int executionIndex = 0; // Index for the executionOrder array

    while (completedProcesses < n) {
        // Find the best process to run among those that have arrived
        int selectedIndex = findNextProcess(processes, n, currentTime);

        if (selectedIndex == -1) {
            // --- CPU Idle ---
            // No process is ready. Find the earliest arrival time of an uncompleted process.
            int minNextArrivalTime = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!processes[i].isCompleted && processes[i].arrivalTime < minNextArrivalTime) {
                    minNextArrivalTime = processes[i].arrivalTime;
                }
            }
            // Advance time only if the next arrival is actually in the future
            if (minNextArrivalTime > currentTime) {
                 currentTime = minNextArrivalTime;
            } else {
                 // This case should ideally not happen if findNextProcess is correct,
                 // but as a safeguard against potential infinite loops if something
                 // arrived exactly at currentTime but wasn't selected, increment time by 1.
                 currentTime++;
            }

        } else {
            // --- Process Execution ---
            Process *p = &processes[selectedIndex]; // Pointer to the selected process

            // Calculate start time: Process starts either when it arrives or when CPU is free, whichever is later.
            p->startTime = (currentTime >= p->arrivalTime) ? currentTime : p->arrivalTime;

            // Calculate completion time
            p->completionTime = p->startTime + p->burstTime;

            // Calculate turnaround time and waiting time
            p->turnaroundTime = p->completionTime - p->arrivalTime;
            p->waitingTime = p->turnaroundTime - p->burstTime; // Or: p->startTime - p->arrivalTime

            // Mark process as completed
            p->isCompleted = 1;

            // Update simulation time to the completion time of the executed process
            currentTime = p->completionTime;

            // Record the index of the executed process
            executionOrder[executionIndex++] = selectedIndex;

            // Increment the count of completed processes
            completedProcesses++;
        }
    }
}


/**
 * @brief Prints the scheduling results in a formatted table and calculates averages.
 * @param processes Array of Process structures containing calculated results.
 * @param n Number of processes.
 * @param executionOrder Array storing the indices of processes in execution order.
 */
void printResults(Process processes[], int n, int executionOrder[]) {
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    printf("\n--- Scheduling Results (Execution Order) ---\n");
    printf("===============================================================================================================\n");
    printf("| PID  | Priority | Arrival Time | Burst Time | Start Time | Completion Time | Waiting Time | Turnaround Time |\n");
    printf("===============================================================================================================\n");

    // Print processes IN THE ORDER THEY EXECUTED
    for (int i = 0; i < n; i++) {
        int processIndex = executionOrder[i]; // Get the index from the execution order array
        Process p = processes[processIndex]; // Get the data for that process

        printf("| %-4d | %-8d | %-12d | %-10d | %-10d | %-15d | %-12d | %-15d |\n",
               p.pid, p.priority, p.arrivalTime, p.burstTime,
               p.startTime, p.completionTime, p.waitingTime, p.turnaroundTime);

        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnaroundTime;
    }

    printf("=====================================================================================================\n");

    // --- Calculate and Print Averages ---
    if (n > 0) {
        printf("\nAverage Waiting Time:    %.2f\n", totalWaitingTime / n);
        printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
    } else {
        printf("\nNo processes to calculate averages.\n");
    }
     printf("--------------------------------------------------\n");
}
