#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
#define ll long long 
#define vi vector<int>
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

using namespace std;

bool is_valid(string &s)
{
	int root = sqrt( s.size() );
	
	if (root*root == s.size()) { return true; }
	
	return false;
}

void solve()
{
	string s;
	int root; 

	getline(cin, s);

	if ( is_valid(s) )
	{
		root = sqrt( s.size() );

		f(i,0,root)
		{
			f(j,0,root)
			{
				cout << s[ (j*root) + i ];
			}
		}
		cout << endl;
	}
	else
	{
		cout << "INVALID\n";
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int T;
	cin >> T;
	
	while (T--)
	{
		solve();
	}
}

