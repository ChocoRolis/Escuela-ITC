#include <bits/stdc++.h>
using namespace std;

int main()
{
	int num, cont;
	
	cin >> num;

	int permutations[ num ];

	if ( num % 2 == 0  &&  num != 2 )
	{
		cont = num;
		for (int i = 1; i < num; i = i + 2)
		{
			permutations[ i ] = cont;
			--cont;
		}

		cont = num / 2;

		for (int i = 0; i < num - 1; i = i + 2)
		{
			permutations[ i ] = cont;
			--cont;
		}

		for (int i = 0; i < num; ++i)
		{
			cout << permutations[ i ] << " ";
		}

		cout << endl;
	}
	else if ( num % 2 == 1  &&  num != 3 )
	{
		cont = num;
		for (int i = 0; i < num; i = i + 2)
		{
			permutations[ i ] = cont;
			--cont;
		}
		
		cont = num / 2;

		for (int i = 1; i < num - 1; i = i + 2)
		{
			permutations[ i ] = cont;
			--cont;
		}

		for (int i = 0; i < num; ++i)
		{
			cout << permutations[ i ] << " ";
		}

		cout << endl;
	}
	else 
	{
		cout << "NO SOLUTION\n";
	}

	return 0;
}
