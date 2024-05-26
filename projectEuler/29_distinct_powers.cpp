#include <iostream>
#include <cmath>
#include <set>
using namespace std;

typedef long double ld;

int main()
{
	set<ld> distinct_nums;
	ld power;

	for (ld i = 2; i <= 100; ++i)
	{
		for (ld j = 2; j <= 100; ++j)
		{
			power = pow(i, j);
			distinct_nums.insert( power );
		}
	}

	cout << distinct_nums.size() << endl;
}
