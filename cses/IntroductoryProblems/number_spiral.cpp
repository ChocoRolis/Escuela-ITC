#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll num_diagonal(int num)
{
	return (long long) num * num - (num - 1);
}

void solve()
{
	int rows, columns;
	cin >> rows >> columns;
	
	if (rows == columns)
	{
		cout << num_diagonal(rows) << endl;
	}
	else if (rows > columns)
	{
		ll diagonal = num_diagonal(rows);
		int negativo = -1;
		
		if (rows % 2 == 0) { negativo = 1; }

		cout << diagonal + negativo * (rows - columns) << endl;
	}
	else
	{
		ll diagonal = num_diagonal(columns);
		int negativo = 1;
		
		if (columns % 2 == 0) { negativo = -1; }

		cout << diagonal + negativo * (columns - rows) << endl;
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
