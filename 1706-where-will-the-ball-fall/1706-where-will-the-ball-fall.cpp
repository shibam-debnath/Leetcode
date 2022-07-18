class Solution
{
public:
    vector<int> res;
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            dfs(grid, n, m, 0, i);
            // res.push_back(i);
        }
        
        return res;
    }

    void dfs(vector<vector<int>> &grid, int row, int col, int i, int j)
    {
        // base
        if (i >= row){
            res.push_back(j);
            return;
        }
            
        // 3 dead locks
        if (grid[i][j] == 1)
        {
            if (j == col-1 || grid[i][j + 1] == -1){
                res.push_back(-1);
                return;
            }
                
        }

        if (grid[i][j] == -1)
        {
            if (j == 0 || grid[i][j - 1] == 1){
                res.push_back(-1);
                return;
            }
                
        }

        // recursive call
        dfs(grid, row, col, i + 1, j + grid[i][j]);

    }
};