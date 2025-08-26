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

void solve(string& s1, string& s2)
{
	string result = "";

	f(i, 0, s1.size())
	{
		f(j, 0, s2.size())
		{
			if (s1[ i ] == s2[ j ])
			{
				result += s1[ i ];
				s2[ j ] = '.';

				break;
			}
		}
	}

	sort( all(result) );

	cout << result << endl;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;

	while (cin >> s1 >> s2)
	{
		solve(s1, s2);
	}
}
