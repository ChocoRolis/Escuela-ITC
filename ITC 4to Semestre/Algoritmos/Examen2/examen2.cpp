#include <iostream>

using namespace std;

int main()
{
	int H, M, caso = 1; // Cantidad de hombres (H), de mujeres (M) y el numero de caso.
	
	 // Bucle para cada caso. El while lee H y M y si ambos son 0 se termina el programa.
	 while ( cin >> H >> M   &&   0 != H && 0 != M ) 
	 {
		int hombre, mujer, edad_min = 99; // No se necesitan guardar los datos en arreglos.

		// Input de edades de hombres y luego de mujeres.
		for (int i = H; i > 0; --i)
		{
			cin >> hombre;	
			if (hombre < edad_min) { edad_min = hombre; } // Se saca el que tiene la edad minima.
		}
		for (int i = M; i > 0; --i)
		{
			cin >> mujer;
		}

		if (H <= M) // Si hay igual o menos hombres que mujeres, siempre sobran 0.
		{
			cout << "Caso " << caso << ": 0\n";
		}
		else
		{
			cout << "Caso " << caso << ": " << H - M << " " << edad_min << "\n";
		}
		
		caso++;
	}

	return 0;
}
