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

	vector< pair<int,int> > solves;

	int i = 0;
	while (i < size  &&  size_team > 0)
	{
		int tmp = students[i];
		int cant = count_if( solves.begin(), solves.end(), [tmp](pair<int,int>& p) {
				return p.first == tmp;
			} );

		if ( cant == 0 )
		{
			solves.push_back( make_pair(tmp, i+1) );
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
		for (auto &a : solves) { cout << a.second << " "; }
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
