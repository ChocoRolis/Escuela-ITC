#include <stdio.h>
#include <string.h>
#include <dirent.h>

void print_files(const char* dirname)
{
	DIR* dir = opendir(dirname);
	struct dirent* file;
	
	if (!dir) { return; } 

	file = readdir(dir);
	printf("\tleyendo desde %s\n", dirname);

	while (file)
	{
		if (strcmp(file->d_name, ".") && strcmp(file->d_name, ".."))
		{
			printf("%s/%s\n", dirname, file->d_name);

			if (file->d_type == DT_DIR)
			{
				char path[128] = { 0 };
				strcat(path, dirname);
				strcat(path, "/");
				strcat(path, file->d_name);

				print_files(path);
			}
		}
		file = readdir(dir);
	}

	closedir(dir);
}

int main(int argc, char** argv)
{
	if (argc > 1) 
		print_files(argv[1]);

	return 0;
}
