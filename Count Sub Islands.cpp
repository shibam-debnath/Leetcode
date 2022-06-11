// Shibam Debnath
// June,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    bool clone = true;

    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
    {
        int n = grid1.size(), m = grid1[0].size();
        // remove invalid cases
        if (i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] != 1)
            return;

        if (grid1[i][j] == 0) // grid2 is 1 bit grid1 is 0
        {
            clone = false;
            return;
        }

        grid2[i][j] = 0;

        dfs(grid1, grid2, i + 1, j);
        dfs(grid1, grid2, i, j + 1);
        dfs(grid1, grid2, i - 1, j);
        dfs(grid1, grid2, i, j - 1);
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int count = 0;
        int n = grid1.size(), m = grid1[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] == 1)
                {
                    clone = true;
                    // this func call makes it false if not a clone island
                    dfs(grid1, grid2, i, j);

                    if (clone)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
    }
    return 0;
}