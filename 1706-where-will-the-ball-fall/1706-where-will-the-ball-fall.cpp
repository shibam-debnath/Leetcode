class Solution
{
public:
    
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> res;
        for (int i = 0; i < m; i++)
        {
            int ans = dfs(grid, n, m, 0, i);
            res.push_back(ans);
        }
        return res;
    }

    int dfs(vector<vector<int>> &grid, int row, int col, int i, int j)
    {
        // base
        if (i >= row) return j;
            
        // 4 dead locks
        
        //left diagonal
        if (grid[i][j] == 1) 
            if (j == col-1 || grid[i][j + 1] == -1) return -1;

        //right diagonal
        if (grid[i][j] == -1)
            if (j == 0 || grid[i][j - 1] == 1) return -1;

        // recursive call
        return dfs(grid, row, col, i + 1, j + grid[i][j]);

    }
};