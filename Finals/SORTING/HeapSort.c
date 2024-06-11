// Heap
int left(int i) {return i * 2 + 1;}
int right(int i) {return i * 2 + 2;}

void Swap(int* A, int x, int y)
{
    int t = A[x];
    A[x] = A[y];
    A[y] = t;
}

void Heapify(int* A, int i, int heapSize)
{
    int leftChild = left(i);
    int rightChild = right(i);

    int min = i;

    if (leftChild < heapSize && A[leftChild] > A[min])
    {
        min = leftChild;
    }
    if (rightChild < heapSize && A[rightChild] > A[min])
    {
        min = rightChild;
    }

    if (min != i)
    {
        Swap(A, i, min);
        Heapify(A, min, heapSize);
    }
}

void buildHeap(int* A, int heapSize)
{
    for (int i = heapSize / 2; i >= 0; i--)
    {
        Heapify(A, i, heapSize);
    }
}

// HeapSort
void HeapSort(int* A, int heapSize)
{
    buildHeap(A, heapSize);
    int size = heapSize - 1;
    while (size > 0)
    {
        Swap(A, 0, size);
        Heapify(A, 0, size);
        size--;
    }
}
