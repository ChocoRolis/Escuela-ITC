#include <bits/stdc++.h>
using namespace std;

vector<string> permutations;
bool used_digits[10] = {};
string digits = "0123456789", cadena = "";

void solve(int n)
{
	if (n >= digits.size())
	{
			permutations.push_back( cadena );
	}
	else
	{
		for (int i = 0; i < digits.size(); ++i)
		{
			if (used_digits[ i ]) { continue; }

			used_digits[i] = true;
			cadena += digits[ i ];

			solve(n+1);

			used_digits[ i ] = false;
			cadena.erase( cadena.begin() + n );
		}
	}
}

int main()
{
	solve(0);
	cout << permutations[999999] << endl;
}
