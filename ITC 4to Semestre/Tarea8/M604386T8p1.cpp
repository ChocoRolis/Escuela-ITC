//Rolando Rivas #594276
//Angel Muñoz #604386

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// estructuras para las coordenadas de cada cosa
struct Puntos {
    int x, y;
};

struct Aristas {
    int u, v;
    double valor;
};

class Uniones {
private:
    vector<int> origen, destino; // origen: padre de cada vertice, destino: altura de cada vertice, basicamente los x,y

public:
    Uniones(int n) : origen(n), destino(n, 0) { // constructor
        for (int i = 0; i < n; ++i)
            origen[i] = i;
    }

    int buscar(int x) { // busca el padre de un nodo
        return origen[x] == x ? x : (origen[x] = buscar(origen[x]));
    }

    void unir(int x, int y) { // une dos vertices segun las distancias mas cortas y los ubica de forma balanceada en el arbol
        int rootX = buscar(x), rootY = buscar(y);
        if (rootX != rootY) {
            if (destino[rootX] < destino[rootY])
                origen[rootX] = rootY;
            else {
                origen[rootY] = rootX;
                if (destino[rootX] == destino[rootY])
                    destino[rootX]++;
            }
        }
    }
};

double distancia(const Puntos& p1, const Puntos& p2) { // como puede ir en linea recta queremos la hipotenusa
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double kruskal(int n, const vector<Puntos>& vertices, const vector<Aristas>& conexiones) { 
    vector<Aristas> aristasOrd = conexiones;
    sort(aristasOrd.begin(), aristasOrd.end(), [](const Aristas& a, const Aristas& b) { 
        return a.valor < b.valor;
    });

    Uniones uf(n); //ir guardando las uniones de los vertices 
    double longTotal = 0.0;

    for (const Aristas& Aristas : aristasOrd) { // recorre aristas y va uniendo los vertices desconectados con la distancia mas corta
        int u = Aristas.u, v = Aristas.v;
        double valor = Aristas.valor;
        if (uf.buscar(u) != uf.buscar(v)) { 
            uf.unir(u, v);
            longTotal += valor;
        }
    }

    return longTotal;
}

int main() {
    int k;
    cin >> k;

    cout.precision(2);
    cout << fixed; // Para que se muestren con dos cifras decimales

    while (k--) {
        int n;
        cin >> n;
        vector<Puntos> vertices(n);
        for (int i = 0; i < n; ++i)
            cin >> vertices[i].x >> vertices[i].y;

        int c;
        cin >> c;
        vector<Aristas> caminosExist(c);
        for (int i = 0; i < c; ++i) {
            cin >> caminosExist[i].u >> caminosExist[i].v;
            --caminosExist[i].u;
            --caminosExist[i].v;
            caminosExist[i].valor = 0.0; // los que ya existen no agregan costo
        }

        vector<Aristas> conexiones;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dist = distancia(vertices[i], vertices[j]); 
                conexiones.push_back({i, j, dist}); // se guardan las distancias entre los vertices
            }
        }

        conexiones.insert(conexiones.end(), caminosExist.begin(), caminosExist.end()); // se unen los caminos existentes con los nuevos para registro final

        cout << kruskal(n, vertices, conexiones) << endl; // mostra costo total
    }

    return 0;
}
