#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

void solve()
{
	int k_ocurrence, to_find;
	cin >> k_ocurrence >> to_find;

	int i = 0, index = 0;

	while (k_ocurrence != 0  &&  i <= arr.size())
	{
		if (arr[ i ] == to_find)
		{
			--k_ocurrence;
			if (k_ocurrence < 1)
			{
				index = i + 1;
				break;
			}
	}
		++i;
	}
	cout << index << endl;
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
			arr.push_back(tmp);
		}

		while (queries--)
		{
			solve();
		}

		arr.clear();
	}
}


