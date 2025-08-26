#include <bits/stdc++.h>
using namespace std;

int camino_mas_corto(int **adyacencias, int nodoInicio, int nodoFinal)
{
	return **adyacencias;
}

const int a = 100000, b = 100000;

void algo( int ptr[a][b] )
{
	cout << ptr[0][0] << endl;
}




int main()
{
	//int &nodos = a, &aristas = b; 
	//cin >> nodos >> aristas;
	
	int adyacencias[ a ][ b ] = {};

	for (int i = 0; i < aristas; ++i)
	{
		int adyacencia_inicio, adyacencia_fin, peso;
		cin >> adyacencia_inicio >> adyacencia_fin >> peso;
		
		adyacencias[ adyacencia_inicio - 1 ][ adyacencia_fin - 1 ] = peso;
	}

	int **ady_ptr= (int**) &adyacencias;

	algo(ady_ptr);
	//cout << camino_mas_corto( ady_ptr, 0, nodos - 1) << endl;
	//cout << *(*(ady_ptr + 0) + 0) << endl;
}
