#include <iostream>
#include <string>
using namespace std;

//Rolando Rivas #594276
//Angel Muñoz #604386
//Tarea 4

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
