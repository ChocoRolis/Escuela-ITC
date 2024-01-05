#include <iostream>
#include <string>
using namespace std;

int residuo(string Num) {
    int s = 0, i, n;
    for (i = 0; i<8; i++){
        n = (int) Num[i];
        n = n - 48;
        s = s + (i * n);
    }
    n = s % 11;
    return n;
}

int main(){
    char Char = 'Y', h;
    int r;
    string num;
    while (Char == 'Y'){
        cout << "Teclea el numero de 9 digitos" << endl;
        cin.ingore();
        getline(cin, num);
        r = residuo(num);
        if (r < 10){
            h = (char) r;
            num += (h + 48);
        }
        else if (r > 10) {
            num += "X";
        }
        cout << "Tu nuevo ISBN es " << num << endl;
        cout << "Quieres repetir el proceso? (Y/n)";
        cin >> Char;        
    }
}
