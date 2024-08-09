#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
#define ll long long 
#define vi vector<int>
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

using namespace std;

int solve(int n, int nums[])
{
	int cont = 0;
	int tmp;

	return cont;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int shoes1[ n ], shoes2[ n ];

	for (int i = 0; i < n; ++i)
	{
		cin >> shoes1[ i ];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> shoes2[ i ];
	}

	cout << solve(n, shoes1) + solve(n, shoes2) << endl;
}

