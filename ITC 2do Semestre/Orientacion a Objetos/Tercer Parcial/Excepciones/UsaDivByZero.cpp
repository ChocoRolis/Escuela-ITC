#include <iostream>
#include "DivByZeroExc.h"
using namespace std;

double division(int num, int den){
  if (den == 0){
    throw DivByZeroExc{};
  }
  return (double)num / den;
}

int main() {
  int num, den;
  cout << "Dame dos numeros, esc para terminar\n";
  while (cin>>num>>den){
    try{
      double resultado = division(num, den);
      cout << " el resultado es "<< resultado <<  endl;
    }
      catch (DivByZeroExc &e){
        cout << " ocurrio una excepcion: "<< e.what() << endl;
      }
    cout << " Dame dos numeros, esc para terminar \n ";
  }
  cout << endl;
}