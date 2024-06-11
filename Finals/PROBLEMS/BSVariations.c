/*Assume the array is sorted. Find and describe an algorithm with sublinear (i.e., less than linear)
asymptotic complexity that determines the missing number. Determine the asymptotic worst-case complexity of your algorithm.*/

/*We use binary search for a sorted array:
– We look for the smallest index i for which A[i] = i + 2; this is the position of our missing number.
– We find the mid element, mid = ⌊n/2⌋. If A[mid] = mid+1 we recurse on the second half of the array A[mid+1..high], 
otherwise we recurse on first half of the array A[low..mid],
– The algorithm terminates when the search range consists of only one element (i.e. A[low] == A[high]) and A[i] = i + 2. 
The missing number is i + 1.*/

int BS_Sorted_1missing(int* A, int l, int r)
{
    if (l == r) return A[l] - 1;
    int m = (l+r)/2;
    
    if (A[m] == m+1) return BS_Sorted_1missing(A, m+1, r);
    return BS_Sorted_1missing(A, l, m-1);
}

int main() {
    // Write C code here
    int A[] = {1,2,3,4,6,7,8,9};
    int n = sizeof(A) / sizeof(A[0]);
    int m = BS_Sorted_1missing(A, 0, n-1);
    printf("%d\n", m); // prints 5

    return 0;
}

/*Consider an array of n integers A[0..n-1]. The array is sorted in ascending order and there are no duplicate elements. 
Assume the array has been rotated i.e., the elements have been shifted multiple times to the right with the last element
being moved to the first position in each step. For instance, A = [10, 20, 25, 40, 52] becomes A = [25, 40, 52, 10, 20] 
after its elements were shifted to the right three times. 
Implement an algorithm that finds the position of an element in a rotated array. 
The asymptotic running time complexity of your algorithm must be O(log n). Use either C or pseudocode for your solution*/

int BS_Shift(int* A, int l, int r, int k)
{
    if (l > r) return -1; // base case
    
    int m = (l+r)/2;
    if (A[m] == k) return m;
    
    if (A[l] <= A[m]) // we check if from the left to m is sorted
    {
        if (k >= A[l] && k <= A[m])
        {
            return BS_Shift(A, l, m-1, k);
          // [ 25(l) , 50 , 75(m) , 10 , 15 ] we're searching for 10, so we check if the interval l < 10 < m contains k
        }
        return BS_Shift(A, m+1, r, k);
    }
    
    if (k >= A[m] && k <= A[r]) // [ 75(l) , 10 , 15(m) , 50 , 25 ]
    {
        return BS_Shift(A, m+1, r, k);
    }
    return BS_Shift(A, l, m-1, k);
}

int main() {
    int A[] = {75, 10, 15, 25, 50};
    int n = sizeof(A) / sizeof(A[0]);
    int target = 25;
    int m = BS_Shift(A, 0, n - 1, target);
    if (m != -1) {
        printf("Element %d found at index %d\n", target, m);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    return 0;
}
