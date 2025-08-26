#include <bits/stdc++.h>
using namespace std;

//Rolando Rivas 594276
//Angel Muñoz 604386

int MAX_PARTICIONES = 0;

bool es_valido(string &cadena)
{
	string tmp = "";
	int cont = 0;
	unordered_set<string> particiones;
	
	for (int i = 0; i <= cadena.size(); ++i)
	{
		if (cadena[i] != '|' && i != cadena.size())
		{
			tmp += cadena[i];	
		}
		else
		{
			if (particiones.count(tmp) == 0) 
			{
				particiones.insert(tmp);
				tmp.clear();
			}
			else { return false; }
		}
	}
	return true;
}

int contar_particiones(string &cadena)
{
	int cont = 0;
	for (int i = 0; i < cadena.size(); ++i)
	{
		if (cadena[i] == '|')
		{
			++cont;
		}
	}
	return ++cont;
}

void particionar(string	cadena, int i)
{
	if (i >= cadena.size()-1)
	{
		if ( es_valido(cadena) )
		{
			int particiones = contar_particiones( cadena );
			MAX_PARTICIONES = max( MAX_PARTICIONES, particiones );
		}
	}
	else
	{
		while ( cadena[i] != '|'  &&  i < cadena.size() ) 
		{
			++i; 
		}

		particionar(cadena, i+1);
		
		cadena.erase(cadena.begin() + i);

		particionar(cadena, i);
	}
}


void solve(string &palabra)
{
	string palabra_dividida = "";

	for (int i = 0; i < palabra.size(); ++i)
	{
		palabra_dividida += palabra[ i ];
		palabra_dividida += "|";
	}
	palabra_dividida.pop_back();

	particionar(palabra_dividida, 0);

	cout << MAX_PARTICIONES << endl; 
	MAX_PARTICIONES = 0;
}

int main()
{
	string palabras;
	while (cin >> palabras)
	{
		solve(palabras);
	}
}
