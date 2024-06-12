/*Given n applicants, the arrays s[n] and v[n] and the available budget
B for new salaries, describe an algorithm that uses dynamic programming to
compute the maximum total value that the company can achieve by hiring the
appropriate applicants. You can use either C or pseudocode for your solution.*/

int knapSack(int* s, int* v, int B, int n)
{
    int dp[B+1][n+1];

    for (int i = 0; i <= B; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= B; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[j-1] < i)
            {
                dp[i][j] = fmax(dp[i-s[j-1]][j-1] + v[j-1], dp[i][j-1]);
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[B][n];
}

int main() {
    int v[] = {6, 5, 3, 7};
    int s[] = {4, 2, 5, 3};
    int n = sizeof(s) / sizeof(s[0]);
    int B = 8;
    
    printf("%d\n", knapSack(s, v, B, n));

    return 0;
}
