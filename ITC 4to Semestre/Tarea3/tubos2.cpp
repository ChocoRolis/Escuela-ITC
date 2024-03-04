#include <iostream>
using namespace std;

void tubos(int &n1, int &n2)
{

}

int main()
{
	int casos; 
	cin >> casos;
	for (int i = 0; i < casos; ++i)
	{
		int cant_nums, objetivo, num1, num2;
		cin >> cant_nums;
		int nums[cant_nums];

		for (int j = 0; j < cant_nums; ++j)
		{
			cin >> nums[j];
		}
		
		cin >> objetivo;
		tubos(num1, num2);
		
		cout << num1 << " " << num2 << "\n";
	}
	return 0;
}
