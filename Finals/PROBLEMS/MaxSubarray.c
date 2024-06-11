typedef struct {
    int leftIndex;
    int rightIndex;
    int sum;
} SubArrayInfo;

SubArrayInfo maxOverlap(int* A, int l, int m, int r)
{
    int leftSum = -9999;
    int sum = 0;
    int maxLefttIndex = m + 1;
    for (int i = m; i >= l; i--)
    {
        sum+=A[i];
        if (sum > leftSum) 
        {
            leftSum = sum;
            maxLefttIndex = i;
        }
    }
    
    int rightSum = -9999;
    sum = 0;
    int maxRightIndex = m + 1;
    for (int i = m+1; i <= r; i++)
    {
        sum+=A[i];
        if (sum > rightSum) 
        {
            rightSum = sum;
            maxRightIndex = i;
        }
    }
    SubArrayInfo Overlap;
    Overlap.leftIndex = maxLefttIndex;
    Overlap.rightIndex = maxRightIndex;
    Overlap.sum = leftSum+rightSum;
    return Overlap;
}

SubArrayInfo maxSubArray(int* A, int l, int r)
{
    if (l == r) {
        SubArrayInfo singleElementInfo;
        singleElementInfo.leftIndex = l;
        singleElementInfo.rightIndex = r;
        singleElementInfo.sum = A[l];
        return singleElementInfo;
    }
    
    int m = (l+r)/2;
    SubArrayInfo maxLeft = maxSubArray(A, l, m);
    SubArrayInfo maxRight = maxSubArray(A, m+1, r);
    SubArrayInfo Overlap = maxOverlap(A, l, m, r);
    
    if (maxLeft.sum > maxRight.sum && maxLeft.sum > Overlap.sum) return maxLeft;
    else if (maxRight.sum > maxLeft.sum && maxRight.sum > Overlap.sum) return maxRight;
    else return Overlap;
    
}

// call: SubArrayInfo m = maxSubArray(A, 0, n-1);
