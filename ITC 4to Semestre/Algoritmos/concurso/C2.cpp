#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> arr;

void solve()
{
	int k, find;
	cin >> k >> find;

	pair<int, int> par = {find, 0};

	auto it = lower_bound(arr.begin(), arr.end(), par);
	
	if (it + k >= arr.end())
	{
		cout << 0 << endl;
	}
	else
	{
		while (--k)
		{
			++it;
		}
		if (it->first == find)
		{
			cout << it->second + 1 << endl;
		}
		else 
		{
			cout << 0 << endl;
		}
	}
	
}

int main()
{
	int size, queries;
	while (cin >> size >> queries)
	{
		if (0 == size && 0 == queries) { break;	}

		int tmp;
		for (int i = 0; i < size; ++i)
		{
			cin >> tmp;
			arr.push_back( make_pair(tmp, i) );
		}

		sort(arr.begin(), arr.end());
		
		while (queries--)
		{
			solve();
		}

		arr.clear();
	}
}
