#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

int main() 
{
	FILE *file = fopen("words.txt", "r");

	int sum = 0, word_sum;
	int num;
	int n = 1;
	int word_count = 0;

	int triangle_nums[1000] = {};
	char words[2000][MAX_WORD_LENGTH];

	while ( fscanf(file, " \"%[^\"]\",", words[word_count]) == 1 ) 
	{
		word_count++;
	}

	fclose(file);

	do {
		num = (n * (n + 1)) / 2;
		triangle_nums[ num ] = 1;
		++n;
	} while (num < 1000);

	for (int i = 0; i < word_count; ++i)
	{
		int j = 0;
		word_sum = 0;

		while (words[i][j] != '\0')
		{
			word_sum += (int) words[i][j] - 'A' + 1;
			++j;
		}

		if ( triangle_nums[word_sum] ) { ++sum; }
	}

	printf("%d\n", sum);

	return 0;
}
