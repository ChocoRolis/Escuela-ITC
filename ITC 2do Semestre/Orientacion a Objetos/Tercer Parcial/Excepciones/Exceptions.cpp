#include <iostream>
using namespace std;

int main(){
    int arr[5];
        int num;
        cout << "Dame un numero: ";
        cin >> num; 
    try {
        for (int i = 0; i < num; i++){
            if (i == 5) throw i;
        }    
        throw 10;
    } catch (int e){
        cout << 'a' << e;
    }
}