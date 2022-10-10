class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;

        for(int i =2;i<=n;i++){
            int mn = INT_MAX;
            for(int k=1;k*k<=i;k++){
                 mn = min(mn,dp[i-(k*k)]);
            }
            dp[i] = 1+ mn;
        }
        return dp[n];
    }
};