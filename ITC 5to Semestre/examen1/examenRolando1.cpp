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

string solve()
{
	string line, result = "", tmp;
	int index_cont = 0;

	while (getline(cin, line)  and  line != "") 
	{
		stringstream ss(line);

		while (ss >> tmp)
		{
			if (index_cont > tmp.size() - 1) { continue; }

			result += tmp[ index_cont ];
			++index_cont;
		}

		result += " ";
		index_cont = 0;
	}

	result.pop_back();
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, cont = 1;
	string null_line;

	cin >> T;
	
	cin.ignore(2);
	//getline(cin, null_line);

	while (T--)
	{
		cout << "Mensaje " << cont++ << ": " << solve() << endl;
	}
}

