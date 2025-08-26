#include <stdio.h>

int main()
{
	int t, n1, n2, n3;
	
	scanf("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		scanf("%d %d %d", &n1, &n2, &n3);
		printf("%d\n", (n1) + (n2 * 256) + (n3 * 65536));
	}
}
