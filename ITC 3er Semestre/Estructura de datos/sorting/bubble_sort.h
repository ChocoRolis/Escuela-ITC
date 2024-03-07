#include <swap.h>
 
void bubbleSort(int arr[], int n)
{
    int cont = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
            else cont++;
        }
        if (cont == n-1) return arr;
        cont = 0;
    }
    return arr;
}
