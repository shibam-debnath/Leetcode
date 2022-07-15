class Solution {
public:
    
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(auto &x : stones)  sum+=x;

        int dp[n+1][sum+1];
        // initalization
        for(int i=0;i<=sum;i++){
            dp[0][i] = 0;             //already 0
        }
        
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        
        // main dp
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(stones[i-1]<=j){
                    // subset sum dp(same)
                    dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j]; 
                    // cout << j << " ";
                }
                else dp[i][j] = dp[i-1][j];    
            }
        }
        
        // now find min subset sum diff
        int mid=0;
        for(int j=0;j<=sum/2;j++){
            if(dp[n][j]==true){
                mid=max(mid,j);
            }
        }
        
        return sum-2*mid;
        
    }
};