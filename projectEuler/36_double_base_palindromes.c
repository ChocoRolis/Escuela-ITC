#include <stdio.h>
#include <stdbool.h>

bool XOR(int a, int b)
{
	if (0 == a && 0 == b) return true;
	if (0 < a && 0 < b) return true;

	return false;
}

bool decimal_is_palindrome( int num )
{
	int reverse_num = 0;
	int digits = num;
	int tmp = 1;

	while (digits / (tmp * 10)) 
	{
		tmp *= 10;
	}

	while (digits)
	{
		reverse_num += (digits % 10) * tmp;
		digits /= 10;
		tmp /= 10;
	}

	return (num == reverse_num);
}

bool binary_is_palindrome( int num )
{
	int i = 31;
	int size_binary;

	while ((num & (1 << i)) == 0)
	{
		--i;
	}

	size_binary = i;

	for (int j = 0; j <= size_binary/2; ++j)
	{
		if ( !XOR(num & (1 << j), num & (1 << i--)) ) 
		{
			return false;
		}
	}

	return true;
}


int main()
{
	int sum = 0;

	for (int i = 1; i < 1000000; ++i)
	{
		if (!decimal_is_palindrome( i )) { continue; }
		if (!binary_is_palindrome( i )) { continue; }

		sum += i;
	}

	printf("%d\n", sum);
}


/*
// VERSION EN C++

#include <bits/stdc++.h>
using namespace std;

bool decimal_is_palindrome( int num )
{
	string a = to_string( num );
	
	for (int i = 0; i < a.size(); ++i)
	{
		if ( a[i] != a[a.size() - i - 1] )
		{
			return false;
		}
	}

	return true;
}

bool binary_is_palindrome( int num )
{
	bitset<32> binary_num( num );
	int i = 32;

	while ( binary_num[i] != 1 ) { --i; }

	for (int j = i; j >= i/2; --j)
	{
		if ( binary_num[j] != binary_num[i - j] )
		{
			return false;
		}
	}

	return true;
}


int main()
{
	int sum = 0;

	for (int i = 1; i < 1000000; ++i)
	{
		if (!decimal_is_palindrome( i )) { continue; }
		if (!binary_is_palindrome( i )) { continue; }

		sum += i;
	}

	cout << sum << endl;
}
*/
