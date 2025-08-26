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

int empty(string s)
{
	string tmp;
	int cont = 0;
	
	if (s == "") { return 1; }

	int j;

	f(i, 0, s.size())
	{
		j = i;
		while (s[i] == s[j+1]) { ++j; }
		
		if (j - i > 0)
		{
			tmp = s;
			tmp.erase(i, j-i+1);
			cont += empty(tmp);
			i += j - i;
		}

		if (cont > 0) { break; }
	}

	return cont;
}


void solve()
{
	string s;
	cin >> s;

	cout << empty( s ) << endl;
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

