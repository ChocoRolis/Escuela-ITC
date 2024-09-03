#include <bits/stdc++.h>
#define EJEMPLO 32
#define ll long long

using namespace std;

void sieve(bool *nums, int size)
{
	int root = sqrt(size);
	int cont = 0;

	memset(nums, true, sizeof(bool) * size);

	for (int i = 2; i <= root; ++i)
	{
		if (nums[i]) 
		{ 
			for (int j = 0; (i*i + i*j) < size; ++j)
			{
				nums[i*i + i*j] = false;
			} 
		}
	}
}

int main()
{
	unordered_set<ll> superpowers = {1};
	bool primes[ EJEMPLO ];

	sieve( primes, EJEMPLO );


	for (ll i = 2; i < EJEMPLO - 30; ++i)
	{
		if (!primes[i]) { continue; }

		for (int j = 1; j <= 32; ++j)
		{
			if (primes[j]) { continue; }

			superpowers.insert( pow(i, j) );
		}
	}

	for (auto a : superpowers)
	{
		cout << a << endl;
	}
}
