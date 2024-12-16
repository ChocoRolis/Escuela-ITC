#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string line;
  ifstream entrada;
  entrada.open("parrafo.txt");
  while(!entrada.eof()){
    getline(entrada,line);
    for(int i = 0; i<line.length();i++){
      if(line[0] > 96){
        line[0] -= 32;
      }
      if(line[i] == ' '){
        line[i+1] -= 32;
      }
    }
    cout<<line<<endl;
  }

  entrada.close();
  return 0;
}