#include <iostream>
#include <string>
#include <vector>

using namespace std;

char pergamino(int indice, int ite)
{
	string cadena = "";
	for (int i = 1; i <= ite; ++i)
	{
		cadena += to_string(i);
	}
	return cadena[indice];
}

char iteracion(int num)
{
	unsigned long int i = 0, a = 0, b = 0, digits = 1, max = 9, ite = 0; 
	
	while (i+a+digits*(b+1) <= num)
	{
		while ((a + b != max) && (i+a+digits*(b+1) <= num))
		{
			i += a + digits*(++b);		
			++ite;
		}	
		a += digits * b;
		b = 0;
		digits++;
		max = max*10 + 9;
	}
	return pergamino(num - i+1, ite);
}

int main()
{
	int casos, num;
	cin >> casos;
	
	for (int i = 0; i < casos; i++)
	{
		cin >> num;
		cout << iteracion(num) << "\n";
	}
	
	return 0;
}
       	
