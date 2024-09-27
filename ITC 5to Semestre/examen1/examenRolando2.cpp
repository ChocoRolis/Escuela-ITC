// Rolando Rivas Examen 2
// 594276
// 13/09/24
// Doy mi palabra que he realizado esta actividad con integridad academica
//

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

#define MAX 10000001 // sqrt -> 3162

bool primes[ MAX ];

void sieve(bool *nums, int size)
{
        int root = sqrt(size);
        int cont = 0;

        memset(nums, true, sizeof(bool) * size);

	nums[ 0 ] = false;
	nums[ 1 ] = false;

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

void solve(int low, int high)
{
	int root, primes_cont, prime_plex_cont = 0;

	for (int i = low; i <= high; ++i)
	{
		if (primes[ i ]) { ++prime_plex_cont; } 

		root = sqrt(i);
		primes_cont = 0;

		for (int j = 2; j <= root; ++j)
		{
			int k = i / j;

			if (primes[ j ]) 
			{
				if (i % j == 0) { primes_cont += j; }
				if (j == k) { continue; }
			}
			if (primes[ k ])
			{
				if (i % k == 0) { primes_cont += k; }
			}	
		}

		if (primes[ primes_cont ]) { ++prime_plex_cont; }
	}

	cout << prime_plex_cont << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	sieve( primes, MAX );
	
	while (cin >> a  &&  a != 0)
	{
		cin >> b;
		solve(a, b);
	}
}

