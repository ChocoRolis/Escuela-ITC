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
	string s, min_s = "~";

	cin >> size >> s;

	s += s.substr(0, size - 1);

	for (int i = 0; i < size; ++i)
	{
		if ( min_s > s.substr(i, size) )
		{
			min_s = s.substr(i, size);
			min_position = i;
		}
	}

	cout << min_position << endl;
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

