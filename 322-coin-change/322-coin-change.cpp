class Solution {
public:
    // Unbounded knapsack variation
    // Time Complexity :::  O(n2)
    // Space Complexity ::: O(n2)
    
    int coinChange(vector<int> &coins, int t)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(t + 1,INT_MAX-5));
    
    // with 0 coins are there we can't form any amount or we need inf coins 
    for (int i = 0; i <= t; i++)
    { 
        dp[0][i] = INT_MAX - 5;
    }
        
    // amount 0 can can be achieved by all coins taking 0 no of coins 
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    
    // Real dp starts from here
   for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            // coin itself is geater than target don't take that ith coin
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i-1][j];
            } 
            // else   min ( nehi lena hein    ||      lena h ) ->if le rhe ho then +1 becoz we are taking one coin
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j -(coins[i-1])] + 1);
            }
        }
    }
        
    return dp[n][t] != INT_MAX-5 ? dp[n][t] : -1;
}
};