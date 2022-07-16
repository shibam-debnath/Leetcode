class Solution {
public:
    
    long long mod = 1e9 + 7;
    
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    
    int dp[51][51][51];
    
    int dfs(int m, int n,int maxMove, int i, int j){
        
        //base case
        if(i>=m || j>=n || i<0 || j<0) return 1;
        
        if(maxMove<=0) return 0;
        
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];
        int res=0; 
        
        // logic
        for(int k=0;k<4;k++){
            res+=dfs(m,n,maxMove-1,i+dx[k],j+dy[k])%mod;
            res%=mod;
        }
        return dp[i][j][maxMove] = res%mod;
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return dfs(m,n,maxMove,startRow,startColumn);
    }
};