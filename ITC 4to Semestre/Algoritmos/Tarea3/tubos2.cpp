#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void tubos(int &n1, int &n2, vector<int> &arr[], int size, int obj)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if (arr[i] + arr[j] == obj)
			{
				if (arr[j] - arr[i] < n1 - n2)
				{
					n1 = arr[j];
					n2 = arr[i];
				}
			}
		}
	}
}

int main()
{
	int casos; 
	cin >> casos;
	for (int i = 0; i < casos; ++i)
	{
		int size, objetivo, num1 = 10000000, num2 = 0;
		cin >> size;
		vector<int> nums[size];

		for (int j = 0; j < size; ++j)
		{
			cin >> nums[j];
		}
		
		cin >> objetivo;
		sort(nums.begin(), nums.end());
		tubos(num1, num2, nums, size, objetivo);
		
		cout << num1 << " " << num2 << "\n";
	}
	return 0;
}
