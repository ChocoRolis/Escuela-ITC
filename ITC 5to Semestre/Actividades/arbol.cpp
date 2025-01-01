#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

bool existe(map<int,int> &ABB, int pos)
{
	try {
   	ABB.at(pos);
		return true;
  }
  catch (const std::out_of_range& oor) {
   	return false;
  }
}

void insertar(map<int,int> &ABB, int valor)
{
	int pos=0; //comenzamos en la raiz
	while(existe(ABB,pos)) //mientras la pos exista
	{
		if(valor<ABB[pos]) //a la izquierda
			pos=pos*2+1;
		else //derecha
			pos=pos*2+2;
	}
	ABB[pos]=valor; //Se inserta
}

void preorden(map<int,int> &ABB,int pos)
{
	if(!existe(ABB,pos))
		return;

	cout<<ABB[pos]<<" ";

	preorden(ABB,pos*2+1); //izq
	preorden(ABB,pos*2+2); //derecho
}

void inorden(map<int,int>& ABB, int pos)
{
	if(!existe(ABB,pos))
	{
		return;
	}

	inorden(ABB,pos*2+1); //izq

	cout<<ABB[pos]<<" ";

	inorden(ABB,pos*2+2); //derecho
}

void postorden(map<int,int>& ABB, int pos)
{
	if(!existe(ABB,pos))
	{
		return;
	}

	postorden(ABB,pos*2+1); //izq
	postorden(ABB,pos*2+2); //derecho

	cout<<ABB[pos]<<" ";
}

void eliminar(map<int,int>& ABB, int pos) // INCOMPLETO
{
	if (!existe(ABB, pos*2 + 1)  &&  !existe(ABB, pos*2 + 2))
	{
		ABB.erase(pos);
		return;
	}

	if (existe(ABB, pos*2 + 1))
}


int main()
{
	map<int,int> ABB;
	insertar(ABB,7);
	insertar(ABB,3);
	insertar(ABB,0);
	insertar(ABB,-3);
	insertar(ABB,1);
	insertar(ABB,5);
	insertar(ABB,4);
	insertar(ABB,6);
	insertar(ABB,20);
	insertar(ABB,15);
	insertar(ABB,25);
	insertar(ABB,30);

	preorden(ABB,0);
	cout << endl;
	inorden(ABB,0);
	cout << endl;
	postorden(ABB, 0);

	/*for(auto e:ABB)
	{
		cout<<"En "<<e.first<<" hay un "<<e.second<<endl;
	}*/
}
