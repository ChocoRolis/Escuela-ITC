#include <bits/stdc++.h>
using namespace std;

int n, Size;
vector<int> nums;
vector<int> subset;

void solve(int k)
{
	if (k == Size) 
	{
		int cont = 0; 
		for (int i = 0; i < subset.size(); ++i)
		{
			cont += nums[ i ];
		}
		if (cont == n)
		{
			for (int a : subset) cout << a << " ";
			cout << "= " << n << endl;
		}
	}
	else
	{
		subset.push_back( nums[k] );
		solve(k + 1);
		subset.pop_back();
		solve(k + 1);
	}
}

int main()
{
	while (cin >> n >> Size)
	{
		if (0 == n && 0 == Size)
		{
			break;
		}

		int tmp;
		for (int i = 0; i < Size; i++)
		{
			cin >> tmp;
			nums.push_back(tmp);
		}

		solve(0);
	}
}
