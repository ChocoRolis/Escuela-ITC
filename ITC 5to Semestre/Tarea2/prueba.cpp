#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
#define ll long long 
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

using namespace std;

void solve()
{
	int size, min_position;
	list<int> pos;
	string s;
	char min_s = '~';

	cin >> size >> s;

	s += s.substr(0, size - 1);

	f(i, 0, size)
		min_s = min( min_s, s[i] );
	f(i, 0, size)
		if (min_s == s[i]) { pos.pb(i); }

	for (auto i : pos)
	{
		if (i == 3) pos.erase(@s
	cout << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	while (T--)
	{
		solve();
	}
}

