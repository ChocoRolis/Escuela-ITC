#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> nums;
	int size, tmp;

	cin >> size;

	for (int i = 0; i < size; ++i)
	{
		cin >> tmp;
		nums.insert(tmp);
	}
	
	cout << nums.size() << endl;
}
