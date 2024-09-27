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

#define MAX 10000001 

int primes[ MAX ];
int sum_factors[ MAX ];

void sieve(int *nums, int *factors, int size)
{
        for (int i = 2; i < size; ++i)
        {
                if (nums[ i ]) { continue; }

                for (int j = i*2; j <= size; j += i)
                {
                        nums[ j ] = i;
			factors[ j ] += i;
                }
        }
}

void solve(int low, int high)
{
	int root, primeplex_cont = 0;

	for (int i = low; i <= high; ++i)
	{
		if ( !primes[ sum_factors[i] ] )
		{
			++primeplex_cont;
		}
	}

	cout << primeplex_cont << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	sieve( primes, sum_factors, MAX );
	
	while (cin >> a  &&  a != 0)
	{
		cin >> b;
		solve(a, b);
	}
}


