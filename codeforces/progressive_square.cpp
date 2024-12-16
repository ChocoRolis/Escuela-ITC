#include <bits/stdc++.h>
using namespace std;

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

bool are_equal(int *arr1, int *arr2, int size)
{
	bool flag = true;
	for (int i = 0; i < size; ++i)
	{
		if (arr1[i] != arr2[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

void solve()
{
	int n, c, d;
	cin >> n >> c >> d;
	int size = n*n;
	int nums[ size ];
	for (int i = 0; i < size; ++i)
	{
		cin >> nums[i];
	}

	int square[size] = {0};
	
	sort(nums, nums + size);
	square[0] = nums[0];

	for (int i = n; i < size; i += n)
	{
		square[i] = square[i - n] + c;
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = n*i + 1; j < n*(i+1); ++j)
		{
			square[j] = square[j - 1] + d;
		}
	}
	
	sort(square, square + size);

	if ( are_equal(nums, square, size) )
	{
		yes();
	}
	else
	{
		no();
	}
}

int main()
{
	int cases;
	cin >> cases;
	for (; cases > 0; --cases)
	{
		solve();
	}
}
