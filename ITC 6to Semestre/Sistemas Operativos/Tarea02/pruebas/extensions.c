#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define EXTENSION ".txt"

// Function to check if a filename has the desired extension
int has_extension(const char *filename, const char *ext) {
    size_t len_filename = strlen(filename);
    size_t len_ext = strlen(ext);
    
    if (len_filename < len_ext) {
        return 0; // Filename is shorter than the extension
    }

    return strcmp(filename + (len_filename - len_ext), ext) == 0;
}

int main() {
    struct dirent *entry;
    DIR *dir = opendir(".");

    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (has_extension(entry->d_name, EXTENSION)) {
            printf("Found text file: %s\n", entry->d_name);
            
            // Open and read the file (optional)
            FILE *file = fopen(entry->d_name, "r");
            if (file) {
                char buffer[256];
                printf("Contents of %s:\n", entry->d_name);
                while (fgets(buffer, sizeof(buffer), file)) {
                    printf("%s", buffer);
                }
                fclose(file);
                printf("\n");
            } else {
                perror("Error opening file");
            }
        }
    }

    closedir(dir);
    return 0;
}

