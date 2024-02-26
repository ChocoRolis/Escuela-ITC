#include <stdio.h>

int main()
{
	int h1, h2;
	do {
		scanf("%d", &h1);
		scanf("%d", &h2);

		int nums1[h1], nums2[h2];

		for (int i = 0; i < h1; i++)
		{
			scanf("%d", nums1[i]);
		}
		for (int i = 0; i < h2; i++)
		{
			scanf("%d", nums2[i]);
		}



	} while (h1 != 0 && h2 != 0);	
	return 0;
}
