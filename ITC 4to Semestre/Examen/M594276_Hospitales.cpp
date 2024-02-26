#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 8 8 8 7 2

int optimaze(vector<int>& Nums, int indice)
{
	int suma = 0;	
	while (Nums[indice] == Nums[indice + 1])
	{
		suma++;
		indice++;
	}
	return suma;
}

int main()
{
	int h1, h2;

	do {
		cin >> h1 >> h2;
		vector<int> nums(h1 + h2);
		vector<int> conflicts;

		for (int i = 0; i < h1; i++) cin >> nums[i];

		for (int i = 0; i < h2; i++) cin >> nums[h1 + i];

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == nums[i + 1])
			{
				conflicts.push_back(nums[i]);
				int desplazar = optimaze(nums, i);
				nums.erase(nums.begin() + i, nums.begin() + i + desplazar);
			}
		}			
		
		for (int i = 0; i < nums.size(); i++)
		{
			cout << conflicts[i] << " ";
		}
		cout << "\n" << nums.size() << "\n";
	} while (h1 != 0 && h2 != 0);
	return 0;
}
