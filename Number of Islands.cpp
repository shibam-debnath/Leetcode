// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();

        if (grid[i][j] == '0' || i < 0 || j < 0 || i == m || j == n)
        {
            return;
        }
        // visited part
        grid[i][j] = '0';

        // check if adjascent nodes are visited or not if not then dfs
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // if non visited themn dfs
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};

int main()
{
    // Main function goes here
    return 0;
}