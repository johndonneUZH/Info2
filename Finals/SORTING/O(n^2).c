void bubbleSort(int* A, int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void selectionSort(int* A, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int k = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        int t = A[i];
        A[i] = A[k];
        A[k] = t;
    }
}

void insertionSort(int* A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        int x = A[i];
        while(j>= 0 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}
