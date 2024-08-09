#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int main()
{
	ll val, sum;
	ll arr[1000001] = {1, 2, 4, 8, 16, 32, 63};
	cin >> val;

	if (val < 7) 
	{ 
		printf("%lld\n", arr[val - 1]); 
		return 0;
	}

	for (int i = 7; i < val; ++i)
	{
		sum = 0;
		for (int j = i - 1; j >= i - 6; --j)
		{
			sum = (sum + arr[ j ]) % MOD;
		}
		arr[ i ] = sum;
	}

	cout << arr[val - 1] << endl;
	return 0;
}


/*
 * TOP DOWN (not working)
ll dp[1000000] = {};

ll dice(const int val, ll sum)
{
	if (sum == val) { return 1; }
	if (sum > val) { return 0; }
	if (dp[sum] != 0) { return dp[sum]; }

	ll combinations = 0;
	for (ll i = 1; i <= 6; ++i)
	{
		combinations += dice(val, sum + i);
	}

	dp[sum] = combinations;
	return combinations;
} 

int main()
{
	int val;

	cin >> val;
	cout << dice(val, 0) << endl;
}
*/
