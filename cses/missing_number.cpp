#include <iostream>
using namespace std;

int main()
{
	int n, temp;
	int nums[200000] = {0};
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> temp;
		nums[temp - 1] = temp;
	}
	for (int i = 0; i < 200000; i++)
	{
		if (nums[i] == 0)
		{
			cout << i + 1 << "\n";
			break;
		}
	}
	return 0;
}
