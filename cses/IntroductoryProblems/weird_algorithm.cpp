#include <iostream>

using namespace std;

void weird(unsigned long int num)
{
	if (num == 1) {
		cout << num << "\n";
		return;
	}
	else if (num % 2 == 0) {
		cout << num << " ";
		return weird(num / 2);
	}
	else {
		cout << num << " ";
		return weird(3*num + 1);
	}
}

int main()
{
	unsigned long int Num;
	cin >> Num;
	weird(Num);
	return 0;
}
