class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return LIS(dp,t,s);
    }
    
    int LIS(vector<vector<int>>& dp, string s , string t){
        
        int n= s.size();
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (s[i - 1] == t[j - 1])
                {
                    // cout << s[i-1] <<  "  " << i-1 << endl;
                    // remove 1 from both i.e take both
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    // take wo wala jisko leke max val ayega
                    // take max of both since it is subsequence . if it was substr we should have taken 0
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                
            }
        }
        
        return dp[n][n];
    }
};