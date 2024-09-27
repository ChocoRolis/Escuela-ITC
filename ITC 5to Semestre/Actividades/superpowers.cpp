#include <bits/stdc++.h>
#define EJEMPLO 294967296
#define ll unsigned long long

using namespace std;

bool primes[ EJEMPLO ];

void sieve(bool *nums, ll size)
{
	int root = sqrt(size);
	int cont = 0;

	memset(nums, true, sizeof(bool) * size);

	nums[ 0 ] = false;
	nums[ 1 ] = false;

	for (ll i = 2; i <= root; ++i)
	{
		if (nums[i]) 
		{ 
			for (ll j = 0; (i*i + i*j) < size; ++j)
			{
				nums[i*i + i*j] = false;
			} 
		}
	}
}

int main()
{
	set<ll> superpowers = { 1 };

	sieve( primes, EJEMPLO );
	
	for (ll i = 2; i < EJEMPLO; ++i)
	{
		//if (!primes[i]) { continue; }

		for (int j = 2; j <= 32; ++j)
		{
			if (primes[j]) { continue; }

			if ((ll) pow(i,j) > 0)
			{
				superpowers.insert( pow(i, j) );
			}
			else { break; }
		}
	}

	for (auto a : superpowers)
	{
		cout << a << endl;
	}

}

// 9219364293862491136
// 18445618199572250625
