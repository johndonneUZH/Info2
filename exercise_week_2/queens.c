#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int N = 4;
int count = 0;
/**
* Check if it’s safe to place a new Queen in the given position
*/
bool isSafe(int board[N][N], int row, int col) 
{
    int i, j;
    
    // check straight
    for (i = 0; i <= col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (i = 0; i <= row; i++)
    {
        if (board[i][col])
        {
            return false;
        }
    }

    // check upleftside diagonal from point
    for (j = row, i = col; j >= 0 && i >= 0; j--, i--)
    {
        if (board[j][i])
        {
            return false;
        }
    }
    
    // check uprightside diagonal from point
    for (j = row, i = col; j < N && i >= 0; j++, i--)
    {
        if (board[j][i])
        {
            return false;
        }
    }

    //check downleftside diagonal from point
    for (j = row, i = col; j >= 0 && i < N; j--, i++)
    {
        if (board[j][i])
        {
            return false;
        }
    }

    return true;
}

/**
* Try to place the N queens in the board
* and update the global variable ’count’
*/
void solveNQueens(int board[N][N], int row)
{
    if (row == N)
    {
        count++;
        return;
    }
    
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, row, i))
        {
            board[row][i] = 1;
            solveNQueens(board, row + 1);
            board[row][i] = 0;
        }
    }
}

int main() {
    int board[N][N];
    memset(board, 0, sizeof(board)); //initialize the board and fill with 0
    solveNQueens(board, 0);
    printf("%i \n", count);
}
