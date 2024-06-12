int quickSelect(int array[], int leftIndex, int rightIndex, int k)
{
    if (leftIndex == rightIndex)
        return array[leftIndex];

    int pivotIndex = hoarePartition(array, leftIndex, rightIndex);

    if (k == pivotIndex)
        return array[k];
    else if (k < pivotIndex)
        return quickSelect(array, leftIndex, pivotIndex - 1, k);
    else
        return quickSelect(array, pivotIndex + 1, rightIndex, k);
}

float findMedian(int* A, int l, int r, int len)
{
    if (len % 2 == 1)
    {
        return quickSelect(A, l, r, len / 2);
    }
    else
    {
        int mid1 = quickSelect(A, l, r, len / 2 - 1);
        int mid2 = quickSelect(A, l, r, len / 2);
        return (mid1 + mid2) / 2.0;
    }
}
