class Solution {
public:
// similar to house robber , it only needs a simple modification
int deleteAndEarn(vector<int>& nums) {
int n=10001;
unordered_map<int,int> mp;
vector<int> dp(n);
for(auto &i : nums){
mp[i] += i;
}
dp[0]=0;
dp[1]=mp[1];
for (int i=2;i<n;i++){
dp[i] = max(dp[i-2]+mp[i] , dp[i-1]);
}
return dp[n-1];
}
};