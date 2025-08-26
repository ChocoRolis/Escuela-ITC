#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n, tmp;
	do 
	{
		int repetidos[100001] = {};
		int no_repetidos_cont = 0;
		int @sz

		cin >> m >> n;

		for (int i = 0; i < m; ++i)
		{
			cin >> tmp;
			++repetidos[ tmp ];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> tmp;
			++repetidos[ tmp ];
		}

		qsort(repetidos, 1000001, sizeof(int), compare);

		for (int i = 0; i < 1000001; ++i)
		{
			if (!repetidos[i]) { continue; }
			if (repetidos[i] == 1) { ++cont; } 
			else { print(repetidos[i]); }
		}


	} while (0 != m && 0 != n);
}

