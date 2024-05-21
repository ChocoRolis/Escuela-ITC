#include <stdio.h>

typedef long long ll;

ll routes(int i, int j)
{
    ll memo[i + 1][j + 1] = {};

    for (int k = 0; k <= i; ++k)
    {
        memo[k][0] = 1;
    }
    for (int k = 0; k <= j; ++k)
    {
        memo[0][k] = 1;
    }

    for (int k = 1; k <= i; ++k)
    {
        for (int l = 1; l <= j; ++l)
        {
            memo[k][l] = memo[k - 1][l] + memo[k][l - 1];
        }
    }

    return memo[i][j];
}

int main()
{
    ll num_routes = routes(20, 20);
    printf("%lld\n", num_routes);
}


/* TOP DOWN
#include <stdio.h>

typedef long long ll;

ll memo[21][21] = {};

ll routes(int i, int j)
{
    if (0 == i || 0 == j)
    {
        return 1;
    }
    if (memo[i][j] != 0)
    {
        return memo[i][j];
    }

    ll a = routes(i - 1, j);
    ll b = routes(i, j - 1);

    memo[i][j] = a + b;

    return memo[i][j];
}

int main()
{
    ll num_routes = routes(20, 20);
    printf("%lld\n", num_routes);
}
*/
