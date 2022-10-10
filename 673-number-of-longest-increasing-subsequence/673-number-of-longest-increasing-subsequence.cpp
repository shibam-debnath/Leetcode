class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size(); 
        vector<int> dp(n, 1),freq(n,1);

        int mx=0,ans = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                
                if (nums[j] < nums[i])
                {
                    // if taking j we again get LIS size then update freq
                    if(dp[j]+1==dp[i]) freq[i]+=freq[j]; 
                    
                    // if taking j we get a larger inc subseq take it and also update freq
                    if(1+dp[j]>dp[i]){
                        dp[i] = dp[j] + 1 ;
                        freq[i]=freq[j];
                    }
                }
            }
            
            if(dp[i]==mx) ans+=freq[i];
                
            if(dp[i]>mx){
                mx=dp[i];
                ans=freq[i];
            }
        }
        
        return ans;
    }
};