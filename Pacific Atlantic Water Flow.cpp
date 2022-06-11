// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<vector<bool>> pacific, atlantic;
    // to store ans
    vector<vector<int>> ans;
    int prev_val = 0;
    void dfs(vector<vector<int>> &h, vector<vector<bool>> &vis, int i, int j)
    {
        int n = h.size();
        int m = h[0].size();

        // same pacific matrix me revisit mat kro
        if (vis[i][j])
            return;

        // update if not visited
        vis[i][j] = true;

        if (pacific[i][j] && atlantic[i][j]) // intersetion points
        {
            ans.push_back(vector<int>{i, j}); // store index
        }

        // simultaneously check for invalid and valid cases
        if ((i + 1) < n && h[i + 1][j] >= h[i][j])
            dfs(h, vis, i + 1, j);
        if ((i - 1) >= 0 && h[i - 1][j] >= h[i][j])
            dfs(h, vis, i - 1, j);
        if ((j + 1) < m && h[i][j + 1] >= h[i][j])
            dfs(h, vis, i, j + 1);
        if ((j - 1) >= 0 && h[i][j - 1] >= h[i][j])
            dfs(h, vis, i, j - 1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
    {
        if (h.empty())
            return ans;

        int n = h.size();
        int m = h[0].size();

        pacific.resize(n, vector<bool>(m, false));
        atlantic.resize(n, vector<bool>(m, false));

        // dfs for pacific (edges - left + top)
        // dfs for atlantic (edges - bottom + right)

        for (int i = 0; i < m; i++)
        {
            dfs(h, pacific, 0, i);
            dfs(h, atlantic, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(h, pacific, i, 0);
            dfs(h, atlantic, i, m - 1);
        }

        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}