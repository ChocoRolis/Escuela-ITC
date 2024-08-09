#include <stdio.h>

void prueba(int n)
{
	int arr[n];
	
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);

	prueba(n);
}
