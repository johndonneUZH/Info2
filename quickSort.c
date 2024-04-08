#include "stdio.h"
#include "stdbool.h"

int COUNTER = 0;

int hoarePartition(int A[], int leftIndex, int rightIndex);
void swap(int A[], int leftIndex, int rightIndex);
void quickSort(int A[], int leftIndex, int rightIndex);

int main(void)
{
    int A2[] = {1,2,3,4,5,6,8,7,9};
    int length2 = sizeof(A2) / sizeof(A2[0]);
    printf("ARRAY: ");
    quickSort(A2, 0, length2 - 1);
    for (int i = 0; i < length2; i++)
    {
        printf("%i ", A2[i]);
    }
    printf("\n");
    printf("COUNTER: %i\n", COUNTER);
}

void swap(int A[], int leftIndex, int rightIndex)
{
    int tmp = A[leftIndex];
    A[leftIndex] = A[rightIndex];
    A[rightIndex] = tmp;
}

int hoarePartition(int A[], int leftIndex, int rightIndex)
{
    int pivot = A[rightIndex];
    int i = leftIndex - 1;
    int j = rightIndex + 1;

    while (true)
    {
        do
        {
            j--;
            COUNTER++;
        } while (A[j] > pivot);

        do
        {
            i++;
            COUNTER++;
        } while (A[i] < pivot);

        if (i >= j) 
        {
            return i;
        }
        swap(A, i, j);

    }
}

void quickSort(int A[], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int m = hoarePartition(A, leftIndex, rightIndex);
        quickSort(A, leftIndex, m - 1);
        quickSort(A, m, rightIndex);
    }
}