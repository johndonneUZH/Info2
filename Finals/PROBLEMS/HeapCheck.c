int controlMaxHeapIterative(int array[], int currentIndex, int length)
{
    for (int i = 0; i < length; i++)
    {
        int leftChild = left(i);
        int rightChild = right(i);

        if (rightChild < length && array[rightChild] > array[i]) { return i; } // right child is bigger
        else if (leftChild < length && array[leftChild] > array[i]) { return i; } // left child is bigger
    }
    return -1;
}

int controlMaxHeapRecursion(int array[], int currentIndex, int length)
{
    int leftChild = left(currentIndex);
    int rightChild = right(currentIndex);
    int largest = currentIndex;

    if (leftChild < length && array[leftChild] > array[largest])
        largest = leftChild;

    if (rightChild < length && array[rightChild] > array[largest])
        largest = rightChild;

    if (largest != currentIndex)
        return currentIndex;

    if (leftChild < length)
    {
        int leftViolation = controlMaxHeapRecursion(array, leftChild, length);
        if (leftViolation != -1)
            return leftViolation;
    }

    if (rightChild < length)
    {
        int rightViolation = controlMaxHeapRecursion(array, rightChild, length);
        if (rightViolation != -1)
            return rightViolation;
    }

    return -1;
}
