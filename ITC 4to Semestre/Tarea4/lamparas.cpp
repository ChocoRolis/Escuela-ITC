#include <iostream>
#include <string>
using namespace std;

int lamparas(string &calle, int size)
{
	int cont = 0;
	for (int i = 0; i < size; ++i)
	{
		if (calle[i] == '+')
		{
			cont++;
			i = i + 2;
		}	
	}
	return cont;
}

int main()
{
	int casos, metros;
	string calzada;

	cin >> casos;
	
	while (casos--)
	{
		cin >> metros;
		cin >> calzada;
		
		cout << lamparas(calzada, metros) << "\n";
	}
	return 0;
}
