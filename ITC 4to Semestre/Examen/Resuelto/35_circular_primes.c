#include <stdio.h>
#include <stdbool.h>

bool digits_are_odd(int num)
{
    int tmp;
    while (num)
    {
        tmp = num % 10;
        if (tmp % 2 == 0 && tmp != 0)
        {
            return false;
        }
        num /= 10;
    }

    return true;
}

bool rotations_are_prime(int i)
{

}

int main()
{
    int sum = 13;
    for (int i = 101; i < 500; i += 2)
    {
        if (!digits_are_odd( i )) { continue; } 
        if (!rotations_are_prime( i )) { continue; }

        ++sum;
        printf("%d ", i);
    }

    printf("%d\n", sum);
}