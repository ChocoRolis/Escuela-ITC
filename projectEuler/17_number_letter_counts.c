#include <stdio.h>

int main()
{
	int one_to_nineteen[] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
			  	6, 6, 8, 8, 7, 7, 9, 8, 8};
	int twenty_to_ninty[] = {6, 6, 5, 5, 5, 7, 6, 6};
	int hundred_and = 10;
	int one_thousand = 11;
	int letters = 0;

	for (int i = 0; i < 19; ++i)
	{
		letters += one_to_nineteen[i];
	}

	for (int i = 0; i < 8; ++i)
	{
		letters += twenty_to_ninty[i];
		
		for (int j = 0; j < 9; ++j)
		{
			letters += twenty_to_ninty[i] + one_to_nineteen[j];
		}
	}
	
	for (int k = 0; k < 9; ++k)
	{
		letters += one_to_nineteen[k] + hundred_and - 3;

		for (int i = 0; i < 19; ++i)
		{
			letters += one_to_nineteen[k] + hundred_and + one_to_nineteen[i];
		}

		for (int i = 0; i < 8; ++i)
		{
			letters += one_to_nineteen[k] + hundred_and + twenty_to_ninty[i];
		
			for (int j = 0; j < 9; ++j)
			{
				letters += one_to_nineteen[k] + hundred_and + twenty_to_ninty[i] + one_to_nineteen[j];
			}
		}
	}
	
	letters += one_thousand;

	printf("%d\n", letters);

	return 0;
}
