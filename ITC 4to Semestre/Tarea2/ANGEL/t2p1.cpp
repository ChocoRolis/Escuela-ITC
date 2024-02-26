#include <iostream>
#include <vector>

using namespace std;

bool esPosibleAlcanzarLongitud(int longitudObjetivo, const vector<int>& tubos, int indice, int sumaActual) {
    if (sumaActual == longitudObjetivo) {
        return true; // Se alcanzó la longitud objetivo
    }

    if (indice == tubos.size() || sumaActual > longitudObjetivo) {
        return false; // No se puede alcanzar la longitud objetivo con esta combinación
    }

    // Incluir el tubo actual en la combinación
    if (esPosibleAlcanzarLongitud(longitudObjetivo, tubos, indice + 1, sumaActual + tubos[indice])) {
        return true;
    }

    // Excluir el tubo actual de la combinación
    return esPosibleAlcanzarLongitud(longitudObjetivo, tubos, indice + 1, sumaActual);
}

int main() {
    int casos;
    cin >> casos;

    for (int caso = 0; caso < casos; ++caso) {
        int longitudObjetivo, numTubos;
        cin >> longitudObjetivo >> numTubos;

        vector<int> tubos(numTubos);
        for (int i = 0; i < numTubos; ++i) {
            cin >> tubos[i];
        }

        if (esPosibleAlcanzarLongitud(longitudObjetivo, tubos, 0, 0)) {
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}