void Swap(int* A, int x, int y)
{
    int t = A[x];
    A[x] = A[y];
    A[y] = t;
}

int hoarePartition(int* A, int l, int r)
{
    int pivot = A[l];
    int i = l+1;
    int j = r;

    while (i <= j)
    {   
        while (A[i] < pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i <= j){ Swap(A, i, j); }
    }

    Swap(A, l, j);
    return j;
}

void quickSort(int* A, int l, int r)
{
    if (l < r)
    {
        int m = hoarePartition(A, l, r);
        quickSort(A, l, m);
        quickSort(A, m+1, r);
    }
}
