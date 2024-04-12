#include <bits/stdc++.h>
using namespace std;

bool special_cond( int ones, string &lamps )
{
	if ( ones == 2 )
	{
		int index = lamps.find("1");

		if ( lamps[index + 1] == '1'  ||  lamps[index - 1] == '1' )
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int cases, ones_counter = 0, size;
	string lamps;
	cin >> cases;

	for (int i = cases; i > 0; --i)
	{
		cin >> size;
		cin >> lamps;

		for (int i = size - 1; i >= 0; --i)
		{
			if ( lamps[i] == '1' ) 
			{ 
				++ones_counter;
			}
		}

		if ( ones_counter % 2 == 0  &&  special_cond(ones_counter, lamps) )
		{
			cout << "YES" << "\n";
		}
		else 
		{
			cout << "NO" << "\n";
		}

		ones_counter = 0;
	}
}
