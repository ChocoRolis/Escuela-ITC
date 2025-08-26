#include <bits/stdc++.h>
using namespace std;

//Rolando Rivas #594276
//Angel Muñoz #604386

char mapa[1002][1002] = {};
int LETRAS[26] = {};

void BFS(int i, int j, char letra)
{
	queue< pair<int,int> > por_visitar;
	pair<int,int> tmp;

	por_visitar.push( {i, j} );

	while (!por_visitar.empty())
	{
		tmp = por_visitar.front();
		por_visitar.pop();

		int F = tmp.first;
		int S = tmp.second;

		if (mapa[F + 1][ S ] == letra)
		{
			por_visitar.push({F + 1, S});
			mapa[F + 1][ S ] = '.';
		}
		if (mapa[F - 1][ S ] == letra)
		{
			por_visitar.push({F - 1, S});
			mapa[F - 1][ S ] = '.';
		}
		if (mapa[ F ][S + 1] == letra)
		{
			por_visitar.push({F, S + 1});
			mapa[ F ][S + 1] = '.';
		}
		if (mapa[ F ][S - 1] == letra)
		{
			por_visitar.push({F, S - 1});
			mapa[ F ][S - 1] = '.';
		}
	}
}
	

void solve()
{
	static int caso = 1;
	int rows, columns;
	cin >> rows >> columns;
	
	rows += 2;
	columns += 2;

	// input
	for (int i = 1; i < rows - 1; ++i)
	{
		for (int j = 1; j < columns - 1; ++j)
		{
			cin >> mapa[i][j];
		}
	}

	// busqueda y eliminacion de letras iguales
	for (int i = 1; i < rows - 1; ++i)
	{
		for (int j = 1; j < columns - 1; ++j)
		{
			if (mapa[i][j] != '.')
			{
				LETRAS[ mapa[i][j] - 'A' ] += 1; 
				BFS(i, j, mapa[i][j]);
			}
		}
	}

	// Todo lo de abajo es para desplegar la info tal como el profe quiere :')
	// Es un desastre pero de este detalle del profe
	// me di cuenta media hora antes de cerrarse la tarea 

	cout << "Mapa " << caso << ":" << endl;

	array< pair<int, char>, 26 > letras; 

	for (int i = 0; i < 26; i++)
	{
		letras[i].first = LETRAS[i];
		letras[i].second = (char) (i + 'A');
	}

	// Orden descendente
	// Si dos nums son iguales, orden alphabetico
	sort(letras.begin(), letras.end(),
              [](const pair<int,char>& a, const pair<int,char>& b) {
		  if (a.first != b.first) 
		  {
                      return a.first > b.first;
                  } 
		  else 
		  {
                      return a.second < b.second;
                  }
              });

	for (auto &a : letras)
	{
		if (a.first > 0)
		{
			cout << a.second << ":" << a.first << endl;
		}
	}

	memset(mapa, ' ', sizeof mapa);
	memset(LETRAS, 0, sizeof LETRAS);
	++caso;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	for (; cases > 0; --cases)
	{
		solve();
	}
}
