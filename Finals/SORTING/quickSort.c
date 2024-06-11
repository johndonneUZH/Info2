void Swap(int* A, int x, int y)
{
    int t = A[x];
    A[x] = A[y];
    A[y] = t;
}

int hoarePartitionLeft(int* A, int l, int r) {
    int pivot = A[l];
    int i = l - 1;
    int j = r + 1;

    while (1) {
        // Increment i while A[i] < pivot
        do {
            i++;
        } while (A[i] < pivot);

        // Decrement j while A[j] > pivot
        do {
            j--;
        } while (A[j] > pivot);

        // If two pointers met
        if (i >= j)
            return j;

        // Swap elements at i and j
        Swap(A, i, j);
    }
}

int hoarePartitionRight(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        // Increment i while arr[i] < pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Decrement j while arr[j] > pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If two pointers met
        if (i >= j)
            return j;

        // Swap elements at i and j
        Swap(A, i, j);
    }
}

void quickSort(int* A, int l, int r)
{
    if (l < r)
    {
        int m = hoarePartitionRight(A, l, r);
        quickSort(A, l, m);
        quickSort(A, m+1, r);
    }
}
