#include <stdio.h>

typedef long long ll;

int factorial(int num)
{
    if (0 == num) { return 1; }

    int sum = num;
    for (int i = num - 1; i > 0; --i)
    {
        sum *= i;
    }

    return sum;
}

int main()
{
    ll sum = 0;
    int tmp;
    int factorial_digits_sum;
    int digits;

    for (int i = 10; i < 1000000; ++i)
    {
        digits = i;
        factorial_digits_sum = 0;

        while (digits > 0)
        {
            tmp = digits % 10;
            digits /= 10;

            factorial_digits_sum += factorial(tmp);
        }

        if (factorial_digits_sum == i)
        {
            sum += i;
        }
    }

    printf("%lld\n", sum);
}