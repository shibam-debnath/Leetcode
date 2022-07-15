class Solution {
public:
    int n,m;
    int dfs(vector<vector<int>> &v, int i, int j)
    {
        int n = v.size(),m = v[0].size();
        if (i < 0 || j < 0 || i == n || j == m || v[i][j] != 1) return 0;

        v[i][j] = 0;

        return 1 + dfs(v, i + 1, j)+dfs(v, i - 1, j)+ dfs(v, i, j + 1)+ dfs(v, i, j - 1);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans=0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) ans = max(ans,dfs(grid,i,j));
                
        
        return ans;
    }
};