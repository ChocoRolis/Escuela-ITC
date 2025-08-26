#include <stdio.h>
#include <stdlib.h>
#define print(x) printf("%d\n", x)
#define read(x) scanf("%d", &x)

int compare(void *a, void *b)
{
	return ( *(int*)a < *(int*)b );
}

//void solve();

int main()
{
    int m, n, tmp;
    do {
        int repetidos[100001] = {};
	int no_repetidos_cont = 0;

        read(m);
        read(n);

        for (int i = 0; i < m; ++i)
        {
            read(tmp);
            ++repetidos[ tmp ];
        }
        for (int i = 0; i < n; ++i)
        {
            read(tmp);
            ++repetidos[ tmp ];
        }

	qsort(repetidos, 1000001, sizeof(int), compare);

	for (int i = 0; i < 1000001; ++i)
	{
		if (!repetidos[i]) { continue; }
		if (repetidos[i] == 1) { ++cont; } 
		else { print(repetidos[i]); }
	}


    } while (0 != m && 0 != n);
}
