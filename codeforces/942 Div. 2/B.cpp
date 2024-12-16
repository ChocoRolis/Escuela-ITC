#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
#define ll long long 
#define vi vector<int>
#define yes() cout << "YES\n" 
#define no() cout << "NO\n"

using namespace std;

void solve()
{
	string s;
	int n, sum = 0;
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'U') { ++sum; }
	}

	if (sum % 2 == 0) { no(); }
	else { yes(); }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;

	while (c--)
	{
		solve();
	}
}
