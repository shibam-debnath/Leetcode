class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        
        vector<int> dp(n);
        unordered_map<int,int> mp;
        
        for(auto &x : nums){
            mp[x]+=x;
        }
        
        dp[0]=0;
        dp[1]=mp[1];
        
        for(int i=2;i<n;i++){
            // suppose we are at 3
            //         3 ka count + 1 ka count / 2 ka count 
            dp[i]=max((mp[i]+dp[i-2]),dp[i-1]);
        }
        
        return dp[n-1];
    }
};