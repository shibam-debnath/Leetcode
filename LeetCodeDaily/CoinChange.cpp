// Shibam Debnath
// May 21,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int coinChange(vector<int> &coins, int t)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, INT_MAX - 5));

    for (int i = 0; i <= t; i++)
    {   // if we don't tale this row then our logic to fill dp matrix shows index
        // out of bound for i=2 and j=1
        dp[0][i] = INT_MAX - 5;
    }

    for (int j = 1; j <= n; j++)
    {
        dp[j][0] = 0;
    }
    for (int i = 1; i <= t; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[1][i] = i / coins[0];
        }
        else
        {
            dp[1][i] = INT_MAX - 1;
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < t + 1; j++)
        {
            if (coins[i - 1] > j)
            {
                // agar element is > target then store uper val of matrrix since this new element can't be used to get a sum of target
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // if element is smaller than target we have a chance to add or not
                // if we add then 1+ dp[i][j - coins[i - 1]] where this dp value
                // let we can 8 and current num is 5 so we'll search if 8-5==3 is possible to get as a sum or not.
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
        }
    }
    // cout << endl << n << t;
    return dp[n - 1][t] < 1000 ? dp[n - 1][t] : -1;
}
int main()
{
    // Main function goes here
    return 0;
}
