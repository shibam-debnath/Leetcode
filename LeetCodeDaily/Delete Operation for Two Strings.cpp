// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    vector<vector<int>> dp;

    int helper(int i, int j, int n, int m, string word1, string word2)
    {
        //! base cases

        // 1. if both reached end no need  to delete
        if (i == n && j == m)
        {
            return 0;
        }
        // 2. if any one reaches end
        if (i == n || j == m)
        {
            // return max of remaining elements of larger one
            return max(n - i, m - j);
        }

        // * memo
        if (dp[i][j] != INT_MAX)
        {
            return dp[i][j];
        }

        // operation/logic
        if (word1[i] == word2[j])
        {
            // check for next two chars in both string
            return dp[i][j] = helper(i + 1, j + 1, n, m, word1, word2);
        }

        // if they are not same s1 = mmeg   s2 = eg  , so first char are m and e . not same so we have to increment a position but
        // kiska increment kre and note : since we are deleting one elemnt +1 bhi kro
        // coming back to qus kisko delete kre
        // ans - isko dlt krne k baad jo min val return karega i.e jo min deletion lega to make both the strings same usko return kro
        // lets check the code
        return dp[i][j] = 1 + min(helper(i, j + 1, n, m, word1, word2), helper(i + 1, j, n, m, word1, word2));
    } //  +1 due to current character deletion

    int minDistance(string word1, string word2)
    {
        dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, INT_MAX));
        int n = word1.size();
        int m = word2.size();
        return helper(0, 0, n, m, word1, word2);
    }
};



// OR another method 

// find longest common subsequence 
// then subtract total char count - 2*longest common subs

int minDistance(string w1, string w2)
{
    int n = w1.size();
    int m = w2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (w1[i - 1] == w2[j - 1])
            { //  if the char at I and j  are same in both string
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return (n + m) - 2 * dp[n][m];
}

int main()
{
    // Main function goes here
    return 0;
}