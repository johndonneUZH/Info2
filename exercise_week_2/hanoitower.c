#include <stdio.h>

int moveCount = 0;
/**
* Move n disks from source to destination via auxiliary
*/
void hanoi(int n, char src, char aux, char dst) 
{
    if (n <= 1)
    {
        moveCount++;
        printf("step %i: %c -> %c\n", moveCount, src, dst);
    }

    else
    {
        hanoi(n - 1, src, dst, aux);
        moveCount++;
        printf("step %i: %c -> %c\n", moveCount, src, dst);
        hanoi(n - 1, aux, src, dst);
    }
}


int main() 
{
    hanoi(3, 'a', 'c' , 'b');
}
