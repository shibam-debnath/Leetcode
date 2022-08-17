class Solution
{
    public:

    int numTrees(int n)
    {
        vector<int> dp(n+1,0);        

        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n ;i++)
        {
            int l=0;
            int r=i-1;
            while(l<= i-1){
                dp[i] += dp[l]*dp[r];
                l++;r--;
            }
        }

        return dp[n];
    }
};

//Time Complexity : O(N2)
//Space Complexity : O(N), required for recursion and memoization