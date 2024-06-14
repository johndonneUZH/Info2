/*An increasing path in the matrix M is a path where the values of the cells are in strictly increasing
order: M[ik][jk] < M[ik+1][jk+1] for all k. The longest increasing path is an increasing path with the
maximum number of cells (maximum n)*/

int DFS(int r, int c, int previous, int** M, int** DP, int x, int y)
{
    if (r < 0 || r == x ||
        c < 0 || c == y ||
        M[r][c] <= previous) { return 0; }
    if (DP[r][c] != -1) return DP[r][c];

    int res = 1;
    res = fmax(res, 1 + DFS(r+1, c, M[r][c], M, DP, x, y));
    res = fmax(res, 1 + DFS(r-1, c, M[r][c], M, DP, x, y));
    res = fmax(res, 1 + DFS(r, c+1, M[r][c], M, DP, x, y));
    res = fmax(res, 1 + DFS(r, c-1, M[r][c], M, DP, x, y));

    DP[r][c] = res;
    return res;
}

int longest_path(int x, int y, int** M)
{
    int** DP = malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++) {
        DP[i] = malloc(y * sizeof(int));
        for (int j = 0; j < y; j++) {
            DP[i][j] = -1; // Initialize DP array with -1
        }
    }
    int res = 1;
    for (int r = 0; r < x; r++)
    {
        for (int c = 0; c < y; c++)
        {
            res = fmax(res, DFS(r, c, -1, M, DP, x, y));
        }
    }

    return res;
}

int main() {
    int **M = malloc(4 * sizeof(int *));
    for(int i = 0; i < 4; i++)
        M[i] = malloc(6 * sizeof(int));

    int temp[4][6] = {
        {1, 7, 3, 10, 6, 18},
        {3, 2, 5, 6, 9, 16},
        {6, 3, 2, 10, 12, 13},
        {8, 7, 5, 4, 8, 15}
    };

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 6; j++)
            M[i][j] = temp[i][j];

    printf("%d", longest_path(4, 6, M));

    return 0;
}









