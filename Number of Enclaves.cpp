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
        if (i < 0 || j < 0 || i == n || j == m || v[i][j] != 1)
        {
            return;
        }
        // update that these values should not be changed
        v[i][j] = 3;

        dfs(v, i + 1, j);
        dfs(v, i - 1, j);
        dfs(v, i, j + 1);
        dfs(v, i, j - 1);
    }
    int numEnclaves(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        // left and right edge to ignore boundary elements
        for (int i = 0; i < n; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        //  top and bottom
        for (int i = 0; i < m; i++)
        {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}