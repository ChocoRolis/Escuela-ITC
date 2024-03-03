#include <iostream>
#include <string>

using namespace std;

int main()
{
	int sum = 1, max = 1;
	string dna;
	char c = 'K';
	cin >> dna;
	for (int i = 0; i < dna.size(); i++)
	{
		if (dna[i] == c)
		{
			sum++;
			if (sum > max) max = sum;
		}
		else
		{
			c = dna[i];
			sum = 1;
		}
	}
	cout << max << "\n";
	return 0;
}

