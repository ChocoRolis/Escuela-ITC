void insertionSort(int arr[], int n)
    {
        int i, j, tmp;
        for (i = 1; i < n; ++i)
        {
            tmp = arr[i];
            j = i - 1;
            
            while (j >= 0 && tmp < arr[j])
            {
                arr[j + 1] = arr[j];
                --j;
            }
            
            arr[j + 1] = tmp;
        }
    }
