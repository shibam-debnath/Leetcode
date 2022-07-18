class Solution {
public:
    int maxUncrossedLines(vector<int>& text1, vector<int>& text2) {
    int n = text1.size();
    int m = text2.size(); 

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

        
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[j - 1] == text2[i - 1])
            {
                dp[i][j] = dp[i-1][j - 1] + 1; 
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    } 
    
    return dp[m][n];
    }
};