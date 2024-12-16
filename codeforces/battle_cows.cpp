#include <bits/stdc++.h>
using namespace std;
// INCOMPLETO
// 
// AAAAAAAA
int start_battle( int[] cows, int size, int myCow, int start, int swap1, int swap2)
{
	int count = 0, n1, n2;

	n1 = cows[swap1];
	n2 = cows[swap2];
	cows[swap1] = n2;
	cows[swap2] = n1;

	if (start != 0) { ++count; }
	
	++start;

	while ( myCow < cows[start]  &&  start < size )
	{
		++count;
		++start;
	}

	cows[swap1] = n1;
	cows[swap2] = n2;

	return count;
}
	

int main()
{
	int cases, size, my_cow, my_index, bigger_cow_index = -1;

	cin >> cases;

	for (int i = cases; i > 0; --i)
	{
		cin >> size >> my_index;

		--index;
		int cows[ size ];

		for (int j = 0; j < size; ++j)
		{
			cin >> cows[i];
		}

		my_cow = cows[ my_index ];
		
		for (int j = 0; j < my_index; ++j)
		{
			if ( cows[j] > my_cow )
			{
				bigger_cow_index = cows[j];
				break;
			}
		}	

		if ( bigger_cow_index = -1 )
		{
			cout << start_battle( cows, size, my_cow, 0,  
