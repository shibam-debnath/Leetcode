class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& grid,int i,int j,int n,int m){
        // base case 
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1) return grid[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        //logic
        return dp[i][j] = grid[i][j] + min(solve(grid,i+1,j,n,m),solve(grid,i,j+1,n,m));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int i=0,j=0;
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        
        return solve(grid,i,j,n,m);
    }
};