#include <bits/stdc++.h>
using namespace std;

void print_permutations(int num)
{
	vector<int> permutations;

	while (num)
	{
		permutations.push_back( num % 10 );
		num /= 10;
	}

	do
	{
		for (int a : permutations) cout << a;
		cout << endl;
	} while (prev_permutation(permutations.begin(), permutations.end()));
}

int main()
{
	int num;
	cin >> num;

	print_permutations(num);
}
