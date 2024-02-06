#include <iostream>
#include <string>
#include <vector>

using namespace std;

int char_a_int(char num)
{
	return (int) num - 48;
}

string sumas(string num)
{
	long long int suma = 0;
	
	for (long int i = 0; i < num.size(); i++)
		
	{
		suma += char_a_int( num[i] );
	}

	return to_string(suma);
}


int descomposicion(string num)
{
	if (num.size() == 1)
	{
		return char_a_int(num[0]);
	}
	else
	{
		return descomposicion( sumas(num) );
	}
}

int main()
{
	vector<int> resultados;
	string entrada;
	
	while (true)
	{
		cin >> entrada;
		if (entrada == "0") break;
		resultados.push_back( descomposicion(entrada) ); 
	}
	
	for (int i = 0; i < resultados.size(); i++) cout << resultados[i] << "\n";
	
	return 0;	
}
