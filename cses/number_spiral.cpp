#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num_diagonal(int num)
{
	ll cont = 1;
	for (int i = 1; i < num; ++i)
	{
		cont += 2 * i;
	}
	return cont;
}

void solve()
{
	int rows, columns;
	cin >> rows >> columns;
	
	if (rows == columns)
	{
		cout << num_diagonal(rows) << endl;
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
