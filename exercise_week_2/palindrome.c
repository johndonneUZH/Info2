#include <stdio.h>
#include <string.h>

int isPalindrome(char X[], int i, int j) 
{
    if (i >= j)
    {
        return 0;
    }
    
    if (X[i] == X[j])
    {
        return isPalindrome(X, ++i, --j);
    }
    else
    {
        return 1;
    }
}

int main()
{
    char X[] = "1a_b3cD45t54Dc3b_a1";

    int i = isPalindrome(X, 0, strlen(X) - 1);
    if (i == 0)
    {
        printf("This is a palindrome");
    }
    else
    {
        printf("This is NOT a palindrome");
    }
}



