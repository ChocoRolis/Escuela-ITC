#include <iostream>
#include <fstream>
#include <string>
using namespace std;

inline int char_a_int(char num)
{
	return (int) num - '0';
}

int main()
{
    	ifstream entrada;
    	string lineas[100], resultado = "";
    	int temp; 
    
	entrada.open("large_sum.txt");

	for (int i = 0; i < 100; ++i)
	{
		entrada >> lineas[i];
	}

	for (int i = 49; i >= 0; --i)
	{	
		for (int j = 0; j < 100; ++j)	
		{
			temp += char_a_int( lineas[j][i] );	
		}
		resultado = to_string( temp % 10 ) + resultado;
		temp /= 10;	
	}

	resultado = to_string(temp) + resultado;
	
	for (int i = 0; i < 10; ++i)
	{
		cout << resultado[i];
	}

	cout << endl;	

	entrada.close();
    	return 0;
}
