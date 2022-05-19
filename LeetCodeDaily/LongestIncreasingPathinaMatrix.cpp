// Shibam Debnath
// May 19,2022

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int get(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &h)
{
    if (h[i][j] != -1)
    {
        return h[i][j];
    }

    int x[] = {0, 0, 1, -1};
    int y[] = {1, -1, 0, 0};

    int tempp = 0;

    for (int n = 0; n < 4; n++)
    {

        int new_i = x[n] + i;
        int new_j = y[n] + j;

        if (new_i >= 0 && new_j >= 0 && new_i < matrix.size() && new_j < matrix[i].size())
        {
            if (matrix[new_i][new_j] > matrix[i][j])
                tempp = max(tempp, 1 + get(matrix, new_i, new_j, h));
        }
    }

    h[i][j] = tempp;
    return h[i][j];
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    vector<vector<int>> dp;

    int ans = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            ans = mx(ans, get(matrix, new_i, new_j, h))
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {

        solve();
    }
    return 0;
}
