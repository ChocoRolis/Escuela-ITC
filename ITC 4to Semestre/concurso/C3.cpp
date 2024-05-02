#include <bits/stdc++.h>
using namespace std;

multimap<int,int> nums;

void solve()
{
	int k, find;
	cin >> k >> find;

	auto it = nums.lower_bound(find);

        if (it == nums.end())
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
			nums.insert( make_pair(tmp, i) );
		}

		
		while (queries--)
		{
			solve();
		}
		
		nums.clear();
	}
}
