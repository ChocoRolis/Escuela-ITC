#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> costs;
int memo[1000][1000] = {};

int min_cost(int ini, int fin)
{
	if (ini == fin)
	{
		return 0;
	}
	if (memo[ini][fin] != 0)
	{
		return memo[ini][fin];
	}

	int MIN_COST = 2147483647; // MAX_INT
	for (int i = 1; i <= fin - ini; ++i)
	{
		int cost = costs[ini][i] + min_cost(ini + i, fin);
		MIN_COST = min( MIN_COST, cost );
	}

	memo[ini][fin] = MIN_COST;
	return MIN_COST;
}

void solve()
{
	int cant_stations;
	cin >> cant_stations;
	
	for (int i = cant_stations; i > 0; --i)
	{
		vector<int> tmp;
		int entrada;
		for (int j = 0; j < i; ++j)
		{
			cin >> entrada;
			tmp.push_back( entrada );
		}
		costs.push_back( tmp );
	}

	for (int i = 0; i < costs.size(); ++i)
	{
		for (int j = i; j < costs.size(); ++j)
		{
			cout << min_cost(i, j) << " ";
		}
		cout << endl;
	}
	memset(memo, 0, sizeof memo); 
	costs.clear();
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
