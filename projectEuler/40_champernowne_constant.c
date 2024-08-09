#include <bits/stdc++.h>
using namespace std;
// Esta mal el ultimo for
int main()
{
	int result = 1;
	int cont = 0, digits = 1, current = 1;
	string nums = "0";

	while (cont <= 1000001)
	{
		if (current >= pow(10, digits))
		{
			++digits;
		}

		nums += to_string(current);
		cont += digits;

		++current;
	}

	for (int i = 1; i <= 1000000; i *= 10)
	{
		result *= atoi(&nums[ i ]);
	}

	cout << result << endl;
}
