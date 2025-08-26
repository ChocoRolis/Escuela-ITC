#include <bits/stdc++.h>
using namespace std;

/* PROBLEM: https://www.spoj.com/problems/FARIDA/ */

typedef long long ll;

unordered_map<int, ll> resultados;

ll recorrido(int* monsters, int index, int size)
{
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
		ll suma1 = monsters[index] + recorrido(monsters, index + 2, size);
		ll suma2 = monsters[index] + recorrido(monsters, index + 3, size);

		resultados[ index ] = max( suma1, suma2 );

		return resultados[ index ];
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
	
	ll MAX = max( recorrido( monsters, 0, size), recorrido(monsters, 1, size) );

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
