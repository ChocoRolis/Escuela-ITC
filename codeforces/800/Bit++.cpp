#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0, k;
	cin >> k;

	while (k--)
	{
		string s;
		cin >> s;

		if (s == "X++" || s == "++X")
		{
			++n;
		}
		else
		{
			--n;
		}
	}

	cout << n << endl;
}
