// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        return LCSub(dp, S1, S2, n, m);
    }
    
    int LCSub(vector<vector<int>>& dp, string &s, string &t, int n, int m)
    {
        int ans =0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (s[i - 1] == t[j - 1]){
                    // lelo
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans,dp[i][j]);
                }
                
                else
                    dp[i][j] = 0;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends