#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream numeros;
    ofstream archivo;
    string num;
    int x;
    numeros.open("datos.txt");
    archivo.open("resultados.txt");
    while(numeros >> num){
        for (int x = (num.length() - 3); x > 0; x -= 3){
            if (!(num[x] == ' ')){
                num.insert(x,",");
            }
        }
        cout << num << endl;
        archivo << num << endl;
    }
    numeros.close();
    archivo.close();
}