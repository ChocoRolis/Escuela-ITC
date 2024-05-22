#include <stdio.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int residue_exists( int *arr, int size, int num )
{
	int i = size - 1;
	for (int i = size - 1; i >= 0; --i)
	{
		if (arr[ i ] == num)
		{
			return size - i;
		}
	}

	return 0;
}


int count_cycles(int num)
{
	int arr_residues[1000];
	int size_arr = 0;
	int residue = 1;

	while ( !residue_exists(arr_residues, size_arr, residue)  &&  residue != 0 )
	{
		arr_residues[ size_arr++ ] = residue;

		residue *= 10;
		residue %= num;
	}

	return residue_exists( arr_residues, size_arr, residue );
}

int main()
{
	int max_cycle = 1;
	int tmp;
	int d; // value for which 1/d contains the longest recurring cycle in its decimal part;

	for (int i = 2; i < 1000; ++i)
	{
		tmp = count_cycles(i);

		if ( max_cycle < tmp )
		{
			max_cycle = tmp;
			d = i;
		}
	}

	printf("%d\n", d);
}
