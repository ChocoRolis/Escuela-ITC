#include <bits/stdc++.h>
using namespace std;
// TIME LIMIT EXCEEDED
typedef long long ll;

unordered_map<int, int> resultados;

ll recorrido(int* monsters, int index, int size)
{
	if (index == size - 1)
	{
		resultados[ index ] = monsters[index];
		return monsters[index]; 
	}
	if (index >= size)
	{
		return 0;
	}
	if ( resultados.find( index ) != resultados.end() )
	{
		return resultados[index];
	}
	else 
	{
		ll suma = 0;

		for (int i = index; i < size; ++i)
		{
			suma = max( suma, monsters[index] + recorrido(monsters, i + 2, size) );
		}

		resultados[ index ] = suma;

		return suma;
	}
}	

void solve()
{
	static int caso = 1;
	int size;
	cin >> size;

	int monsters[ size ]; 

	for (int i = 0; i < size; ++i)
	{
		cin >> monsters[ i ];
	}
	
	int MAX = max( recorrido( monsters, 0, size), recorrido(monsters, 1, size) );

	cout << "Case " << caso << ": " << MAX << "\n";
	++caso;	

	resultados.clear();
}

int main()
{
	int cases;
	cin >> cases;
	
	for (; cases > 0; --cases)
	{
		solve();
	}
}
