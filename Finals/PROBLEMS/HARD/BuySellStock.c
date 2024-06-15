/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).*/


#define BUY 1
#define SELL 0

int DFS(int i, int buy, int** dp, int pricesSize, int* prices)
{
    if (i >= pricesSize || i < 0) return 0;
    if (dp[buy][i] != -1) return dp[buy][i];
    
    if (buy == BUY)
    {
        int cooldown = DFS(i+1, buy, dp, pricesSize, prices);
        int buyer = DFS(i+1, SELL, dp, pricesSize, prices) - prices[i];
        dp[buy][i] = fmax(buyer, cooldown);
    }
    else
    {
        int cooldown = DFS(i+1, buy, dp, pricesSize, prices);
        int sell = DFS(i+2, BUY, dp, pricesSize, prices) + prices[i];
        dp[buy][i] = fmax(sell, cooldown);    
    }
    return dp[buy][i];

}

int maxProfit(int* prices, int pricesSize) 
{
    int** dp = malloc(2 * sizeof(int*)); 
    for (int i = 0; i < 2; i++) {
        dp[i] = malloc(pricesSize * sizeof(int));
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < pricesSize; j++) {
            dp[i][j] = -1; // Example initialization, set values as needed
        }
    }
    
    return DFS(0, BUY, dp, pricesSize, prices);
}
