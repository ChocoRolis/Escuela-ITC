#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
#define ll long long 
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

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

void solve()
{
	int n;
	map<int,int> arbol;

	cin >> n;

	int arr[ n ];

	f(i, 0, n)
	{
		cin >> arr[ i ];
	}

	rf(i, n-1, 0)
	{
		insertar(arbol, arr[ i ]);
	}

	preorden(arbol, 0);

	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	while (T--)
	{
		solve();
	}
}
