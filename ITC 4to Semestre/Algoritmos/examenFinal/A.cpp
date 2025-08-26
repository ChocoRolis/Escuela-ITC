#include <bits/stdc++.h>
using namespace std;

int cercar(vector<vector<bool>> &campo, int m, int n)
{
	

void solve()
{
	int m, n, a;
	cin >> m >> n >> a;

	vector<vector<bool>> campo(m, vector<bool>(n, false));
	for (int i = 0; i < a; ++i)
	{
		int x, y;
		cin >> x >> y;

		campo[x - 1][y - 1] = true;
	}

	cout << cercar(campo, m, n) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases--)
	{
		solve();
	}
}
