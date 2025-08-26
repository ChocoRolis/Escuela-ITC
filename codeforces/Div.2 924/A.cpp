#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, cont = 0;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	for (int i = 0; i < n; ++i)
	{
		if (a[i] > b[i])
		{
			a.insert(i + a.begin(), b[i]);
			a.pop_back();
			++cont;
		}
	}

	cout << cont << endl;
}

int main()
{
	int c;
	cin >> c;

	while (c--)
	{
		solve();
	}
}
