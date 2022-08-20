class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int t = (target+sum)/2;
        
        if (t > sum || (target+sum)%2 != 0) return 0;
        t=abs(t);
        
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(t+1,-1)); 
        return subset_sum(dp,nums,n,t);
    }
    
    int subset_sum(vector<vector<int>> &dp, vector<int>& nums,int n, int t){
        
        if (n == 0){
            if(t==0) return 1;
            return 0;
        }
        
        if(dp[n][t]!=-1) return dp[n][t];
        
        if(nums[n-1]<= t){
            return dp[n][t] = subset_sum(dp,nums,n-1,t-nums[n-1]) + subset_sum(dp,nums,n-1,t);
        }
        else{
            return subset_sum(dp,nums,n-1,t);    
        }
        
    }
};