// Rolando Rivas 594276 19/08/2024 Doy mi palabra que he realizado esta actividad con integridad academica.
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

bool is_vocal(char c)
{
	string vocal = "AEIOUaeiou";

	f(i, 0, vocal.size())
	{
		if (c == vocal[i]) { return true;}
	}

	return false;
}

void solve(string line)
{
	string tmp;

	f(i, 0, line.size())
	{
		if ( !isalpha(line[i]) )
			continue;

		if ( !is_vocal(line[i]) )
		{
			tmp = line[i];
			line.erase(i, 1);

			while ( isalpha(line[i]) )
				++i;

			line.insert(i, tmp);
			++i;

			line.insert(i, "ay");
			i += 2;
		}
		else
		{
			while ( isalpha(line[i]) )
				++i;

			line.insert(i, "ay");
			i += 2;
		}
	}

	cout << line << endl;
}

int main()
{
	string line;	

	while (getline(cin, line))
	{
		solve(line);
	}
}
