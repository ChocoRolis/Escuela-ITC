#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int pipefd[2];

void* writer_thread(void* arg) {
    char message[] = "Hello from writer thread!";
    write(pipefd[1], message, strlen(message) + 1);
    close(pipefd[1]);
    return NULL;
}

void* reader_thread(void* arg) {
    char buffer[256];
    ssize_t bytes_read = read(pipefd[0], buffer, sizeof(buffer));
    if (bytes_read > 0) {
        printf("Reader thread received: %s\n", buffer);
    }
    close(pipefd[0]);
    return NULL;
}

int main() {
    pthread_t writer, reader;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    pthread_create(&writer, NULL, writer_thread, NULL);
    pthread_create(&reader, NULL, reader_thread, NULL);

    pthread_join(writer, NULL);
    pthread_join(reader, NULL);

    return EXIT_SUCCESS;
}
