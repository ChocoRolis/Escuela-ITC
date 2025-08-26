#include <iostream>
#include <vector>

using namespace std;

int main() {
    int marca, num1, num2, num3;
    vector<int> resultados;

    while (true) {
        cin >> marca >> num1 >> num2 >> num3;

        // Verificar entrada
        if (marca == 0 && num1 == 0 && num2 == 0 && num3 == 0)
            break;

        // Calibrar
        int grados = 2 * 360;

        // Primer movimiento de marca a num1 en sentido antihorario
        grados += ((marca - num1 + 40) % 40) * 9;

        // Vuelta completa
        grados += 360;

        // Segundo movimiento de num1 a num2 en sentido horario
        grados += ((num2 - num1 + 40) % 40) * 9;

        // Tercer movimiento de num2 a num3 en sentido antihorario
        grados += ((num2 - num3 + 40) % 40) * 9;

        resultados.push_back(grados);
    }

    // resultados
    for (int i : resultados) {
        cout << i << endl;
    }

    return 0;
}

