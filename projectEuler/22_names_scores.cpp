#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int lu;

lu calificacion( vector<string>& palabras )
{
	lu sum = 0, cont = 0;
	
	for (int i = 0; i < palabras.size(); ++i)
	{
		for (int j = 0; j < palabras[i].size(); ++j)
		{
			cont += palabras[i][j] - 'A' + 1;
		}
		sum += cont * (i+1);
		cont = 0;
	}
	return sum; 
}

int main()
{
	ifstream entrada;
	entrada.open("names.txt");

	string linea;
	getline(entrada, linea);

	entrada.close();

	for (int i = 0; i < linea.size(); ++i)
	{
		if (linea[i] == ','  ||  linea[i] == '"')
		{
			linea[i] = ' ';
		}
	}

	vector<string> palabras;
	istringstream iss(linea);	
	string nombre;

	while (iss >> nombre)
	{
		palabras.push_back(nombre);
	}

	sort(palabras.begin(), palabras.end());
	
	cout << calificacion( palabras ) << endl;
}
