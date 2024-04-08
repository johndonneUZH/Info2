#include "stdio.h"

int controlMaxHeap(int A[], int currentIndex, int length);
int Right(int i);
int Left(int i);
void swap(int A[], int index1, int index2);
void heapify(int A[], int currentIndex, int length);
void fixHeap(int A[], int length);

int main(void)
{
    int A[] = {5,5,3,2,1,3};
    int length = sizeof(A) / sizeof(A[0]);
    int k = controlMaxHeap(A, 0, length);
    printf("%i\n", k);

    int A2[] = {4,10,3,5,1};
    int length2 = sizeof(A2) / sizeof(A2[0]);
    heapify(A2, 0, length2);
    for (int i = 0; i < length2; i++)
    {
        printf("%i ", A2[i]);
    }
    printf("\n");

    int A3[] = {10,3,5,4,1};
    int length3 = sizeof(A3) / sizeof(A3[0]);
    fixHeap(A3, length3);
    for (int i = 0; i < length3; i++)
    {
        printf("%i ", A3[i]);
    }
    printf("\n");

}

int Left(int i)
{
    return (int) 2*i+1;
}

int Right(int i)
{
    return (int) 2*i+2;
}

int controlMaxHeap(int A[], int currentIndex, int length)
{
    int m = currentIndex;
    int l = Left(currentIndex);
    int r = Right(currentIndex);

    if (l < length)
    {
        if (A[l] > A[m])
        {
            return m;
        }
        
        int leftError = controlMaxHeap(A, l, length);
        if (leftError != -1)
        {
            return leftError;
        }
    }
    if (r < length && A[r] > A[m])
    {
        m = r;
    }
    if (currentIndex != m)
    {
        return m;
    }

    if (l < length) {
        int result = controlMaxHeap(A, l, m);
        if (result != -1)
            return result;
    }

    if (r < length)
    {
        if (A[r] > A[m])
        {
            return m;
        }
        
        int rightError = controlMaxHeap(A, r, length);
        if (rightError != -1)
        {
            return rightError;
        }
    }
    
    return -1;
}

void swap(int A[], int index1, int index2) 
{
    int tmp = A[index2];
    A[index2] = A[index1];
    A[index1] = tmp;
}

void heapify(int A[], int currentIndex, int length)
{
    int l = Left(currentIndex);
    int r = Right(currentIndex);
    int largestNum = currentIndex;

    if (l < length && A[l] > A[largestNum])
    {
        largestNum = l;
    }

    if (r < length && A[r] > A[largestNum])
    {
        largestNum = r;
    }

    if (largestNum != currentIndex)
    {
        swap(A, currentIndex, largestNum);
        heapify(A, largestNum, length);
    }
}

void fixHeap(int A[], int length)
{
    int k = controlMaxHeap(A, 0, length);
    while (k != -1)
    {
        heapify(A, k, length);
        k = controlMaxHeap(A, 0, length);
    }
}