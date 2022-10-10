class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int res=0;
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                // initialization of last row & last col
                if(i==n-1 && j==m-1){
                    dp[i][j] = mat[i][j]-'0';
                }
                else if(i==n-1){
                    dp[i][j] = mat[i][j]-'0';
                }
                else if(j==m-1){
                    dp[i][j] = mat[i][j]-'0';
                }
                else{
                    
                    if(mat[i][j]=='1'){
                        //take min all all three directions bottom , bottom right and right
                        int mn = min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
              
                        dp[i][j] = mn+1; 
                    }
                }
                res=max(res,dp[i][j]); 
            }
        }
        
        return res*res;
    }
};