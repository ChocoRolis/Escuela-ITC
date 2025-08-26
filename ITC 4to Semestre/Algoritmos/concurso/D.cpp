#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int size, size_team;
	cin >> size >> size_team;

	int nums[ size ];
	for (int i = 0; i < size; ++i)
	{
		cin >> nums[ i ]; 
	}

	vector<int> unicos;
	vector<int> indices;

	int i = 0;
	while (i < size  &&  size_team > 0)
	{
		if ( count(unicos.begin(), unicos.end(), nums[i]) == 0 )
		{
			unicos.push_back( nums[i] );
			indices.push_back( i + 1 );
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
		for (int a : indices) { cout << a << " "; }
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

