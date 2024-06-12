/* A possibility to efficiently compute the median of a set S with n values is to maintain a so-called
median heap data structure that consists of two heaps: A max heap for the smaller half of the elements
and a min heap for the larger half of the elements.
Assume a sorted array A[1..n] that includes the n values of S. Let i = ⌈n/2⌉.
Hmax is a max heap that includes values A[1], ..., A[i]. Hmin is a min heap
that includes values A[i + 1], ..., A[n]. The median of S is defined as follows:*/

/*Assume the median-heap data structure. Use C or Pseudocode to implement the functions insert, 
which inserts a new value into the median-heap, and getMedian, which returns the current median value.
You can use any of the following helper functions:
– void minInsert(int val) inserts a new value in a min-heap
– int minDelete() deletes and returns the root value of a min-heap
– int getMinSize() returns the size of min-heap
– void maxInsert(int val) inserts a new value in a max-heap
– int maxDelete() deletes and returns the root value of a max-heap
– int getMaxSize() returns the size of max-heap
*/

balanceHeap()
{
    if (getMaxSize() - getMinSize() > 1) // if maxHeap is bigger than 1 element than the minHeap
    {
        minInsert(maxDelete());
    }

    if (getMinSize() - getMaxSize() > 1) // other way around
    {
        maxInsert(minDelete());
    }
}

insert(int val)
{
    if (getMaxSize() == 0) // maxHeap is empty, we're inserting the first value
    {
        maxInsert(val);
        return;
    }

    if (val > maxHeap[1]) minInsert(val); // if the value we want to insert is bigger than the biggest smallest value we insert it in the other heap
    else maxInsert(val);

    balanceHeap();
}

findMedian()
{
    if (getMaxSize() > getMinSize()) // maxHeap has 1 more element: the median
    {
        return maxHeap[1];
    }
    else if (getMinSize() > getMaxSize()) // other way around
    {
        return minHeap[1];
    }
    else // the sizes are equal, number of elements is equal. return the mean of the two median elements
    {
        return (maxHeap[0] + minHeap[0])/2;
    }
}
