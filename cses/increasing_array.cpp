#include <iostream>
using namespace std;

int main()
{
	int cases;
	unsigned long int sum = 0, temp;
	cin >> cases;
	int nums[cases];
	
	for (int i = 0; i < cases; i++)
	{
		cin >> nums[i];
	}
	
	for (int i = 1; i < cases; ++i)
	{
		if (nums[i - 1] > nums[i])
		{
			temp = 	nums[i - 1] - nums[i];
			sum += temp;
			nums[i] += temp;
		}
	}
	cout << sum << "\n";
	return 0;
}
