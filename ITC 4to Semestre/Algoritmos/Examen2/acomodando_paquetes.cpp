#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int lu;

inline lu fact(lu num)
{
	lu cont = 1;
	
	if (num == 0) { return 1; }

	for (; num > 0; --num)
	{
		cont *= num;
	}

	return cont;
}

lu nCr(lu n, lu r)
{
	return fact(n) / ( fact(n - r) * fact(r) );
}

lu nPr(lu n, lu r)
{
	return fact(n) / fact(n - r);
}

void solve()
{
	lu n, f = 1;
	lu num = 0;

	cin >> n;

	for (lu r = n; r > 0; --r)
	{
		num += nCr(n, r) + fact( f );
		f++; 
	}

	cout << num << endl;
}

int main()
{
	int cases;
	cin >> cases;

	while (cases--)
	{
		solve();
	}
}
