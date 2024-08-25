#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
#define ll long long 
#define vi vector<int>
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

using namespace std;

array< pair<int,char>, 26 > letters;

void solve()
{
	string s;
	getline(cin, s);

	f(i, 0, s.size())
	{
		if (s[i] >= 'a'  &&  s[i] <= 'z')
		{
			++letters[ s[i] - 'a' ].first;
		}
		else if (s[i] >= 'A'  &&  s[i] <= 'Z')
		{
			++letters[ s[i] - 'A' ].first;
		}
	}
}

void print_result()
{
	int i = 0;
	for (char c = 'A'; c != 'Z'+1; ++c)
	{
		letters[i].second = c;
		++i;
	}

	sort(all(letters), [](const pair<int,char>& a, const pair<int,char>& b) {
                  if (a.first != b.first) 
                  {
                      return a.first > b.first;
                  } 
                  else 
                  {
                      return a.second < b.second;
                  }
        }); 

	
	f(i, 0, 26)
	{
		if (letters[i].first == 0) { break; }

		cout << letters[i].second << " " << letters[i].first << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	cin.ignore();
	while (T--)
	{
		solve();
	}

	print_result();
}
