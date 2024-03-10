#include <iostream>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr1[], int arr2[], int n)
{
    int cont = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (arr1[j] > arr1[j+1])
            {
                swap(&arr1[j], &arr1[j+1]);
		swap(&arr2[j], &arr2[j+1]);
            }
            else cont++;
        }
        if (cont == n-1) return;
        cont = 0;
    }
    return;
}

int tiempo_tareas(int informa[], int chamba[], int size)
{
	int max = 0, temp = 0;

	for (int i = size; i >= 0; --i)
	{
		temp += informa[i] + chamba[i];
		for (int j = i+1; j <= size; ++j)
		{
			temp += informa[j];
		}
		if (temp > max) max = temp;
		temp = 0;
	}
	return max;
}

int main()
{
	int tareas;
	while (true)
	{
		cin >> tareas;

		if (tareas == 0) break;

		int informa[tareas], chamba[tareas];

		for (int i = 0; i < tareas; i++)
		{
			cin >> informa[i] >> chamba[i];
		}

		bubbleSort(chamba, informa, tareas);
		cout << tiempo_tareas(informa, chamba, tareas-1) << "\n";
	}
	return 0;
}
