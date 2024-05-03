#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream a;
	a.open("yes.txt");
	int yes = 0, no = 0;
	string tmp;

	while (a >> tmp)
	{
		if (tmp == "Si") yes++;
		else no++;
	}
	cout << yes << " " << no << endl;
}
