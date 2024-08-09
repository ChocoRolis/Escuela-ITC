#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
#define ll long long 
#define vi vector<int>
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

using namespace std;

// Obvio no sirve

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	int nums[ n ];
	f(i, 0, n)
	{
		cin >> nums[ i ];
	}

	int a, b;
	ll sum;
	while (q--)
	{
		sum = 0;
		cin >> a >> b;

		--a; --b;

		for (int i = a; i <= b; ++i)
		{
			sum += nums[ i ];
		}

		cout << sum << endl;
	}
}
