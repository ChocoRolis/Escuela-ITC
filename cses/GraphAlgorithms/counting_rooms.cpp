#include <bits/stdc++.h>
using namespace std;

char Map[1002][1002];

void bfs(int row, int col)
{
	queue< pair<int,int> > to_visit;
        pair<int,int> tmp;

        to_visit.push( {row, col} );

        while (!to_visit.empty())
        {
                tmp = to_visit.front();
                to_visit.pop();

                int F = tmp.first;
                int S = tmp.second;

                if (Map[F + 1][ S ] == '.')
                {
                        to_visit.push({F + 1, S});
                        Map[F + 1][ S ] = '#';
                }
                if (Map[F - 1][ S ] == '.')
                {
                        to_visit.push({F - 1, S});
                        Map[F - 1][ S ] = '#';
                }
                if (Map[ F ][S + 1] == '.')
                {
                        to_visit.push({F, S + 1});
                        Map[ F ][S + 1] = '#';
                }
                if (Map[ F ][S - 1] == '.')
                {
                        to_visit.push({F, S - 1});
                        Map[ F ][S - 1] = '#';
                }
	}
}

int main()
{
	int rooms = 0;
	int n, m;
	cin >> n >> m;

	n += 2; m += 2;

	for (int i = 1; i < n - 1; ++i)
	{
		for (int j = 1; j < m - 1; ++j)
		{
			cin >> Map[ i ][ j ];
		} 
	}

	for (int i = 1; i < n - 1; ++i)
	{
		for (int j = 1; j < m - 1; ++j)
		{
			if (Map[ i ][ j ] == '.') 
			{ 
				bfs(i, j); 
				++rooms;
			}
		} 
	}

	cout << rooms << endl;
}
