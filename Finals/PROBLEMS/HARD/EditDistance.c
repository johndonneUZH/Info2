int edit_distance(char* string1, char* string2, int length1, int length2)
{
	// initialise the dp 2D array
	int** dp = malloc((length1+1) * sizeof(int*));
	for (int i = 0; i <= length1; i++)
	{
		dp[i] = malloc((length2+1) * sizeof(int));
	}

	// set base cases
	for (int i = 0; i <= length1; i++)
	{
		dp[i][0] = i;
	}
	for (int j = 0; j <= length2; j++)
	{
		dp[0][j] = j;
	}

	for (int i = 1; i <= length1; i++)
	{
		for (int j = 1; j <= length2; j++)
		{
			if (string1[i-1] == string2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = fmin(dp[i-1][j-1]+1, fmin(dp[i-1][j]+1, dp[i][j-1]+1));
			}
		}
	}

	int result = dp[length1][length2];

	for (int i = 0; i <= length1; i++)
	{
		free(dp[i]);
	}
	free(dp);
	
	return result;
}

int main(void)
{
	char* s1 = "matteo";
	char* s2 = "MATTEO";
	int length1 = strlen(s1);
	int length2 = strlen(s2);
	printf("Minimum edit distace: %d\n", edit_distance(s1, s2, length1, length2));
	return 0;
}
