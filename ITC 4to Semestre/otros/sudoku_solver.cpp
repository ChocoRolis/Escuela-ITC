#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int S[9][9];

bool sudoku_solver()
{
   //Buscar celda vacía
   bool encontrado=false;
   vector<bool> N(10,false);
   int f,c;
   for(f=0;f<9 && !encontrado;f++)
      for(c=0;c<9 && !encontrado;c++)
         if(S[f][c]==0)
            encontrado=true;
   if(!encontrado) //No hay celdas vacías
      return true;
   f--;c--;
   //Buscar números que se pueden poner
   for(int i=0;i<9;i++) //Buscar por fila
      if(S[f][i]!=0)
         N[S[f][i]]=true;
   for(int i=0;i<9;i++) //Buscar por fila
      if(S[i][c]!=0)
         N[S[i][c]]=true;
   int fcuad=int(f/3)*3;
   int ccuad=int(c/3)*3;
   for(int ff=fcuad;ff<fcuad+3;ff++)
      for(int cc=ccuad;cc<ccuad+3;cc++)
         if(S[ff][cc]!=0)
            N[S[ff][cc]]=true;
   
   //Probar uno por uno los números que se pueden poner
   for(int i=1;i<10;i++)
   {
      if(N[i]==false) //Es un número válido
      {
         S[f][c]=i; //Poner número
         if(sudoku_solver())
            return true;
         S[f][c]=0; //Quitar número
      }
   }
   return false;
}

int main() {
   int casos;
   char d;
   cin>>casos;
   for(int k=0;k<casos;k++)
   {
      for(int f=0;f<9;f++)
      {
         for(int c=0;c<9;c++)
         {
            cin>>d;
            S[f][c]=d-'0';
            cout<<S[f][c]<<" ";
         }
         cout<<endl;
      }
      sudoku_solver();
      cout<<endl;
      for(int f=0;f<9;f++)
      {
         for(int c=0;c<9;c++)
         {
            cout<<S[f][c];
            if((c+1)%3==0)
               cout<<"|";
            else cout<<" ";
         }
         if((f+1)%3==0)
            cout<<endl<<"------------------"<<endl;
         else
            cout<<endl;
      }
   }
}
