#include <bits/stdc++.h>
using namespace std;

int cuts[51] = {};
map< pair<int,int>, int > memoria;

int cutting_sticks( int ini, int fin )
{
	pair<int, int> trozo = {ini, fin};

	if (ini == fin - 1)
	{
		return 0;
	}
	if (memoria.find( trozo ) != memoria.end())
	{
		return memoria[ trozo ];
	}

	int min_costo = INT_MAX;
	int costo;

	for (int i = ini + 1; i < fin; ++i)
	{
		costo = cutting_sticks( ini, i ) + cutting_sticks( i, fin );
		costo += cuts[ fin ] - cuts[ ini ];

		min_costo = min( min_costo, costo );
	}

	memoria[ trozo ] = min_costo;
	return min_costo;
}

int main()
{
	int lenght;
	while (cin >> lenght && lenght != 0)
	{
		int n_cuts;
		cin >> n_cuts;
		
		for (int i = 1; i <= n_cuts; ++i)
		{
			cin >> cuts[ i ];
		}

		cuts[ n_cuts + 1 ] = lenght;

		cout << "The minimum cutting is " << cutting_sticks( 0, n_cuts + 1 ) << ".\n";
	}
}
