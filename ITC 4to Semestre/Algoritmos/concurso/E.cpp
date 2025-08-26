#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;

	if (k % 2 == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		int tmp = 1, t = tmp;
		while ( k != 0 )
		{
			if ( pow(2, tmp + 1) <= k )
			{
				++tmp;
			}
			else
			{
				k -= pow(2, tmp);
				t = tmp;
				tmp = 1;
			}
		}
		cout << t + 1 << endl;
	}

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
