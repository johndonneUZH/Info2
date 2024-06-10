void Merge(int* A, int l, int m, int r)
{
    int leftLength = m - l + 1;
    int rightLength = r - m;

    int leftArray[leftLength];
    int rightArray[rightLength];

    for (int i = 0; i < leftLength; i++)
    {
        leftArray[i] = A[l + i];
    }
    for (int i = 0; i < rightLength; i++)
    {
        rightArray[i] = A[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < leftLength && j < rightLength)
    {
        if (leftArray[i] <= rightArray[j])
        {
            A[k] = leftArray[i];
            i++;
        }
        else
        {
            A[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < leftLength)
    {
        A[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rightLength)
    {
        A[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int* A, int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        Merge(A, l, m, r);
    }
}

// call:     mergeSort(A, 0, n - 1);
