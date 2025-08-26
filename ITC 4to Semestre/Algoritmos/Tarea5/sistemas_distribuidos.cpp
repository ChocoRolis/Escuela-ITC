#include <iostream>
#include <array>
#include <vector>
using namespace std;

int OBJETIVO;
vector< array<int,12> > SOLUCIONES;

void print_array(array<int, 12> &arr)
{
	//print
	cout << "{";
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] != 0)
		{
			cout << arr[i] << " ";
		}
	}
	cout << "}\n";
}

bool existe_solucion( array<int, 12> &arr )
{
	

void sums(int pos, array<int, 12> arr_Nums, int size)
{
	if (pos > size)
	{
		int sum = 0;
		
		for (int i = size; i >= 0; --i)
		{
			sum += arr_Nums[ i ];
		}
		
		if (sum == OBJETIVO)
		{
			if ( existe_solucion( arr_Nums ) )
			{
				print_array( arr_Nums );
			}
		}
	}

	else
	{	
		sums( pos + 1, arr_Nums, size );

		arr_Nums[ pos ] = 0;

		sums( pos + 1, arr_Nums, size );
	}
}

int main()
{
	int size;
	array<int, 12> nums;

	do {
		cin >> OBJETIVO >> size;

		for (int i = 0; i < size; ++i)
		{
			cin >> nums[ i ];
		}
		
		if (0 != OBJETIVO)
		{
			cout << OBJETIVO << "=\n";
			sums(0, nums, size - 1);
		}	

	} while (0 != OBJETIVO && 0 != size);

	return 0;
}
