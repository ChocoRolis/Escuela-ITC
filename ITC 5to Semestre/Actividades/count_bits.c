#include <stdio.h>

int main()
{
	int n1, n2, result;
	scanf("%d %d", &n1, &n2);

	result = n1 ^ n2;
	printf("%d\n", __builtin_popcount(result));
}