#include <iostream>
using namespace std;

// Funcion que regresa el minimo numero de movimientos necesarios para las reinas
int min_moves(int size, int *pos, int **chess)
{


int main()
{
	int size;

	do {
		// Bucle para entrada de datos
		cin >> size;

		int chess_board[ size ][ size ] = {};
		int positions[ size ]; 
		
		for (int i = 0; i < size; ++i)
		{
			cin >> positions[ i ];
		}
			
		//cout << min_moves(size, posiciones) << "\n";	

	} while (size != 0);

	return 0;
}

/*
for (int i = 0; i < dimension; ++i)
{
	for (int j = 0; j < dimension; ++j)
	{
		cout << posiciones[i][j] << " ";
	}
		
	cout << endl;
}
*/
