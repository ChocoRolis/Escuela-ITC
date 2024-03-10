#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Rolando Rivas 594276
// Angel Muñoz 604386

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        vector<int> longitudes(n);
        for (int i = 0; i < n; ++i) {
            cin >> longitudes[i];
        }

        int objetivo;
        cin >> objetivo;

        sort(longitudes.begin(), longitudes.end()); //organizar para comparar opciones

        int izq = 0, der = n - 1; // marcadores para buscar combinaciones
        int a = 0, b = 0;
        int difMin = INT_MAX;

        while (izq < der) { // Busqueda 
            int suma = longitudes[izq] + longitudes[der];
            int difActual = abs(longitudes[izq] - longitudes[der]); 
            // diferencia entre las longitudes y la suma que dan

            if (suma == objetivo) { // marcar combinacion optima actual
                if (difActual < difMin) {
                    a = longitudes[izq];
                    b = longitudes[der];
                    difMin = difActual;
                }
                // Mover marcadores al centro para buscar otras comb
                izq++;
                der--;
            } else if (suma < objetivo) { // recorrer apuntadores segun necesario para buscar combinaciones funcionables
                izq++;
            } else {
                der--;
            }
        }
        /*
        basicamente checa desde esquinas si se puede llegar al objetivo con las longitudes organizadas, si no, se mueve hacia el centro las marcas para buscar otras combinaciones
        si se encuentra una combinacion que de el objetivo, se compara con la combinacion anterior y se guarda la que tenga la menor diferencia entre las longitudes
        si una combinacion no da el objetivo, se mueve el marcador izquierdo si la suma es menor al objetivo, y el derecho si es mayor para revisar otros casos ya que esta organizado el vector
        */

        cout << a << " " << b << endl;
    }

    return 0;
}
