Consider an array A[p..r]. The Partition(A, p, r) procedure given below
returns an index q such that each element of array A[p..q - 1] is less than or
equal to A[q] and each element of A[q + 1..r] is greater than A[q]. Modify
the Partition procedure such that it returns two indices q and t where p ≤
q ≤ t ≤ r and
– all elements of A[q..t] are equal,
– each element of A[p..q - 1] is less than A[q], and
– each element of A[t + 1..r] is greater than A[q].

Algorithm: Partition(A, p, r)
2 x = A[r];
3 i = p-1;
4 for j = p to r − 1 do
5 if A[j] ≤ x then
6 i = i + 1;
7 exchange A[i] with A[j];
8 exchange A[i+1] with A[r];
9 return i+1;


SOLUTION

Partition(A, l, r)
    x = A[l]
    i = l
    h = l

    for j = l+1 to r 
        if A[j] < x
            Swap(A, i, j)
            h++
            i++
        else if A[j] == x 
            Swap(A, h+1, j)
            h++
    return (i, h)
