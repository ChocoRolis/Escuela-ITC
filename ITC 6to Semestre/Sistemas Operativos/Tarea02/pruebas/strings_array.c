#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define NUM_CHILDREN 3
#define NUM_STRINGS 2

int main() {
    int pipes[NUM_CHILDREN][2];
    pid_t children[NUM_CHILDREN];
    char* strings[NUM_CHILDREN][NUM_STRINGS] = {
        {"string1_1", "string1_2"},
        {"string2_1", "string2_2"},
        {"string3_1", "string3_2"}
    };

    // Create pipes
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    // Fork child processes and send data
    for (int i = 0; i < NUM_CHILDREN; i++) {
        children[i] = fork();

        if (children[i] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (children[i] == 0) { // Child process
            close(pipes[i][1]); // Close write end
            char buffer[256];
            for(int j=0; j < NUM_STRINGS; j++){
                ssize_t bytes_read = read(pipes[i][0], buffer, sizeof(buffer));
                if (bytes_read > 0) {
                    printf("Child %d received: %s\n", i, buffer);
                }
            }
            close(pipes[i][0]);
            exit(EXIT_SUCCESS);
        } else { // Parent process
            close(pipes[i][0]); // Close read end
            for(int j = 0; j < NUM_STRINGS; j++){
                write(pipes[i][1], strings[i][j], strlen(strings[i][j]) + 1);
            }
            close(pipes[i][1]); // Close write end
        }
    }

    // Wait for all child processes to finish
    for (int i = 0; i < NUM_CHILDREN; i++) {
        wait(NULL);
    }

    return 0;
}
