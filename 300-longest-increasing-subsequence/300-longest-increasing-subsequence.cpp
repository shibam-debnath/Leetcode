class Solution
{
    public:
    
        int lengthOfLIS(vector<int> &nums)
        {
            int n = nums.size();
            
            vector<int> dp(n,1);
            
            int ans = 1;
            
            for (int i = 0; i < n; i++)
            {
               	// check LIS upto i and store max
                for (int j = 0; j < i; j++)
                {
                    if (nums[j] < nums[i]){
                        //      lena k baad    nehi lene k baad
                        dp[i] = max(1 + dp[j],  dp[i]);
                        
                        ans = max(ans,dp[i]);
                    }
                }
            }
            return ans;
        }
};