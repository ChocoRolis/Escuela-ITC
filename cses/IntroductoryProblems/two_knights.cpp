#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll k;
	cin >> k;
	
	for (ll i = 1; i <= k; ++i)
	{
		cout << (i*i*(i*i-1) / 2) - 4*(i-1)*(i-2) << endl;
	}
}
