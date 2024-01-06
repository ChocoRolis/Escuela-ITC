#include <iostream>
#include <string>
using namespace std;

template<class T>
void muestraCol(T mat[10][10], int size, int col){
    for (int i = 0; i < size; i++){
        cout << mat[col][i] << " ";
    }
    cout << "\n";
}

template<class T>
void muestraMatriz(T mat[10][10], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

template<class T>
T datoMayor(T mat[10][10], int size){
    T datomayor = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (mat[i][j] > datomayor){datomayor = mat[i][j];}
        }
    }
    return datomayor;
}

int main(){
    double dMatNum[10][10]  = { {2.5, 3.8, 4.7}, {2.2, 4.4, 6.6}, {2.5, 3.7, 5.9}};
    string sMatLet[10][10]  = {{"a1", "b2", "c3"}, {"dado", "lente", "tren"}, {"gato", "iguana", "canario"}};
    int iSize = 3;
    int iColumna;
    double dMayor;
    string sMayor;
    
    cout << endl << "Cual columna quieres copiar ";
    cin >> iColumna;
    cout << "primera matriz "<< endl;

    muestraMatriz(dMatNum, iSize);

    cout << "Columna de la primera matriz son " << endl;

    muestraCol(dMatNum, iSize, iColumna);

    cout << "el dato mayor de la matriz es " << endl;

    dMayor = datoMayor(dMatNum, iSize);

    cout << dMayor << endl;

   

    cout << "segunda matriz "<< endl;

    muestraMatriz(sMatLet, iSize);

    cout << "Columna de la primera matriz son " << endl;

    muestraCol(sMatLet, iSize, iColumna);

    cout << "el dato mayor de la matriz es " << endl;

    sMayor = datoMayor(sMatLet, iSize);

    cout << sMayor << endl;         

    return 0;

}