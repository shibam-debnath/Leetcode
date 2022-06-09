// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void dfs(vector<vector<int>> &v, int i, int j)
    {
        int n = v.size();
        int m = v[0].size();
        if (i < 0 || j < 0 || i == n || j == m || v[i][j] != 0)
        {
            return;
        }
        // update that these values should not be changed
        v[i][j] = 1;

        dfs(v, i + 1, j);
        dfs(v, i - 1, j);
        dfs(v, i, j + 1);
        dfs(v, i, j - 1);
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            dfs(grid, i, 0);
            dfs(grid, i, m - 1);
        }
        //  top and bottom
        for (int i = 0; i < m; i++)
        {
            dfs(grid, 0, i);
            dfs(grid, n - 1, i);
        }

        //now cal no of closed islands
        int c = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    c++;
                    dfs(grid, i, j);
                }
            }
        }

        return c;
    }
};

int main()
{
    // Main function goes here
    return 0;
}