// Rolando Rivas 594276
// 19/08/2024
// Doy mi palabra que he realizado esta actividad con integridad academica.

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

// Array for irrelgular plurals
vs singular;
vs plural;

void read_irregulars()
{
	string s1, s2;
	cin >> s1 >> s2;

	singular.pb(s1);
	plural.pb(s2);
}

bool needs_es(string s)
{
	if (s == "ch" || s == "sh" || s[1] == 'o' || s[1] == 's' || s[1] == 'x')
	{
		return true;
	}

	return false;
}

bool needs_ies(string s)
{
	string consonants = "qwrtypsdfghjklzxcvbnm";

	if (find(all(consonants), s[0]) == consonants.end())
	{
		return false;
	}

	return (s[1] == 'y');
}

void solve()
{
	string s, last_two_chars = "";
	cin >> s;

	last_two_chars = s;
	last_two_chars.erase(0, s.size() - 2); 

	f(i, 0, singular.size())
	{
		if (singular[i] == s) 
		{ 
			cout << plural[i] << endl; 
			return;
		}
	}

	if (needs_es( last_two_chars ))
	{
		cout << s << "es\n";
	}
	else if (needs_ies( last_two_chars ))
	{
		s.pop_back();
		cout << s << "ies\n";
	}
	else 
	{
		cout << s << "s\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int L, N;
	cin >> L >> N;
	
	while (L--) { read_irregulars(); }
	while (N--) { solve(); }
}
