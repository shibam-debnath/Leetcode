class Solution
{
    public:
       	// Unbounded knapsack variation

       	// Time Complexity :::  O(mn)
       	// Space Complexity ::: O(mn)

        int coinChange(vector<int> &coins, int t)
        {
            int n = coins.size();
            vector<vector < int>> dp(n + 1, vector<int> (t + 1, INT_MAX - 5));

            // for (int i = 0; i <= t; i++) dp[0][i] = INT_MAX - 5; 

            for (int i = 0; i <= n; i++) dp[i][0] = 0;

           	// Real dp starts from here
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= t; j++)
                {
                    if (coins[i - 1] <= j)
                    {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - (coins[i - 1])] + 1);
                    }
                    else dp[i][j] = dp[i - 1][j];
                }
            }
            return dp[n][t] != INT_MAX - 5 ? dp[n][t] : -1;
        }
};