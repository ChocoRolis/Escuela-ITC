#include <stdio.h>

int power(int num, int exp)
{
    int product = 1;

    for (int i = 0; i < exp; ++i)
    {
        product *= num; 
    }

    return product;
}

int main()
{
    int sum = 0, tmp;
    int fifth_powers_sum;
    int digits, digits_length;

    for (int i = 1000; i < 1000000; ++i)
    {
        digits = i;
        fifth_powers_sum = 0;
        digits_length = 0;

        while (digits / power(10, digits_length) > 0)
        {
            ++digits_length;
        }

        for (int j = 0; j < digits_length; ++j)
        {
            tmp = digits % 10;
            digits /= 10;
            
            fifth_powers_sum += power(tmp, 5);
        }

        if (fifth_powers_sum == i)
        {
            sum += i;
        }
    }

    printf("%d\n", sum);
}