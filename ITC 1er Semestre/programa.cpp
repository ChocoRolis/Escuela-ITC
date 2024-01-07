#include <iostream>
#include <string>
using namespace std;
int main() {
  int c=0,l=0;
  string frase;

  cout<<"Ingrese una frase"<<endl;
  getline(cin,frase);
  l=frase.length();

  for(c=0;c<l;c++){
    frase[c]=tolower(frase[c]);
  }

  for(c=0;c<l;c++){
    if(frase[c]=='a'){
      frase[c]=toupper(frase[c]);
    }
    if(frase[c]=='e'){
      frase[c]=toupper(frase[c]);
    }
    if(frase[c]=='i'){
      frase[c]=toupper(frase[c]);
    }
    if(frase[c]=='o'){
      frase[c]=toupper(frase[c]);
    }
    if(frase[c]=='u'){
      frase[c]=toupper(frase[c]);
    }
  }
  
  cout<<frase<<endl;
    
  
  
}