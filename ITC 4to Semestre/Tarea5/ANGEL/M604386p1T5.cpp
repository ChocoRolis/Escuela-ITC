//Rolando Rivas #594276
//Angel Muñoz #604386
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool atqDiagonal(int col1, int fila1, int col2, int fila2) { //cords de las reinas
    return abs(col1 - col2) == abs(fila1 - fila2); //en caso de iguales hay un atq diagonal
}

int main() {
    int n, movNecesarios = 0;
    while (cin >> n && n != 0) {
        vector<int> columnas(n); //tablero
        for (int i = 0; i < n; ++i) {
            cin >> columnas[i];
        }

        movNecesarios = 0;

        // Calcular movimientos
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (columnas[i] == columnas[j] || atqDiagonal(i, columnas[i], j, columnas[j])) {
                    // Si las reinas se pueden atacar, una se debe mover
                    ++movNecesarios; //problema no ocupa saber cual se mueve o a dodne soooo solo queremos contar
                    break;
                }
            }
        }

        cout << movNecesarios << endl;
    }

    return 0;
}