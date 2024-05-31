#include <stdio.h>
#define print(x) printf("%d\n", x)
#define read(x) scanf("%d", &x)

//void solve();

int main()
{
    int m, n, tmp;
    do {
        int repetidos[100001] = {};

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

        


    } while (0 != m && 0 != n);
}