#include <bits/stdc++.h>
using namespace std;

int cuts[51] = {};
int memo[1000][1000];

int cutting_sticks( int ini, int fin )
{
	if (ini == fin - 1)
	{
		return 0;
	}
	if (memo[ ini ][ fin ] != 0)
	{
		return memo[ ini ][ fin ];
	}

	int min_costo = 9999999;
	int costo;

	for (int i = ini + 1; i < fin; ++i)
	{
		costo = cutting_sticks( ini, i ) + cutting_sticks( i, fin );
		costo += cuts[ fin ] - cuts[ ini ];

		min_costo = min( min_costo, costo );
	}

	memo[ ini ][ fin ] = min_costo;
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

		memset(cuts, 0, sizeof(cuts));
		memset(memo, 0, sizeof(memo));
	}
}
