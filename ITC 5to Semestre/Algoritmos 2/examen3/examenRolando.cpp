// Rolando Rivas 594276

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

int fact(int num)
{
	rf(i, num - 1, 1)
	{
		num *= i;
	}
	return num;
}

int solve(int n, int r)
{
	string nums = "1234567890";
	string row = "";
	vector<vi> restrictions(r, vi(3));
	int valid_cases = 0;
	bool is_valid;

	f(i, 0, n) { row += nums[ i ]; }
	
	f(i, 0, r)
	{
		cin >> restrictions[i][0] >> restrictions[i][1] >> restrictions[i][2];
		
		if (restrictions[i][0] == 10) restrictions[i][0] = 0;
		if (restrictions[i][1] == 10) restrictions[i][1] = 0;
	}

	if (!r) 
	{
		return fact(n);
	}

	//////////////////// Procedimiento ///////////////////////

	do {

		is_valid = true;

		for (auto& a : restrictions)
		{
			int i = 0;
			int distance = 0;

			while (row[i] != (a[0] + '0')	&&	row[i] != (a[1] + '0'))
			{
				++i;
			}

			++distance; ++i;

			while (row[i] != (a[0] + '0')	&&	row[i] != (a[1] + '0'))
			{
				++distance; ++i;
			}

			if (a[2] > 0	&&	a[2] < distance)
			{
				is_valid = false;
				break;
			}
			else if (a[2] < 0	&&	(-1) * a[2] > distance)
			{
				is_valid = false;
				break;
			}
		}

		valid_cases += is_valid;

	} while ( next_permutation(row.begin(), row.end()) );

	return valid_cases;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r;
	
	while (cin >> n >> r)
	{
		if (n == 0  && r == 0) { break; }
		
		cout << solve(n, r) << endl;
	}
}
