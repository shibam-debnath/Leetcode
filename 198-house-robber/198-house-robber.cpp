class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n+1,0);
        
        if(n==1) return nums[0];
        if(n==2) return max(nums[1],nums[0]);
        
        dp[0] = 0;
        dp[1]=nums[0];
        dp[2]=max(nums[1],nums[0]);
        
        for(int i=3;i<=n;i++){
            dp[i]=nums[i-1]+max(dp[i-2],dp[i-3]);
        }
        
        return max(dp[n],dp[n-1]);
    }
};