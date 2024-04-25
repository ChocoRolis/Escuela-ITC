#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int size, size_team;
	cin >> size >> size_team;

	int students[ size ];
	for (int i = 0; i < size; ++i)
	{
		cin >> students[ i ]; 
	}

	vector<int> solves;

	int i = 0;
	while (i < size  &&  size_team > 0)
	{
		if ( count(solves.begin(), solves.end(), students[ i ]) == 0 )
		{
			solves.push_back( i + 1 );
			--size_team;
		}
		++i;
	}
	
	if (size_team > 0)
	{
		cout << "NO\n";
	}
	else 
	{
		cout << "YES ";
		for (int a : solves) { cout << a << " "; }
		cout << endl;
	}
}

int main()
{
	int cases;
	cin >> cases;

	while (cases--)
	{
		solve();
	}
}
