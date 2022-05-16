#include <bits/stdc++.h>
using namespace std;
#define ll long long

queue<pair<int, int>> q;

// vector<vector<int>> dir;

int calc(int row, int col, vector<vector<int>> &grid)
{
    while (!q.empty())
    {

        auto x = q.front();
        int row = x.first;
        int col = x.second;

        if (row == grid.size() && col == grid[0].size())
        {
            return grid[grid.size() - 1][grid[0].size() - 1];
        }

        if (grid[row + 1][col + 1] == 0 && row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
        {
            cout << "safe" << endl;
            q.push({row + 1, col + 1});
            grid[row + 1][col + 1] = 1 + grid[row][col];
        }
        else if (grid[row + 1][col] == 0 && row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
        {
            cout << "safe1" << endl;
            grid[row + 1][col] = 1 + grid[row][col];
            row++;
            q.push({row, col});
            cout << q.front().first << endl;
        }
        else if (grid[row][col - 1] == 0 && row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
        {
            cout << "safe3" << endl;
            grid[row][col + 1] = 1 + grid[row][col];
            col++;
            q.push({row, col});
        }

        q.pop();
    }

    return -1;
}

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int i = n - 1, j = m - 1;
    q.push({0, 0});
    int ans = calc(i, j, grid);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return ans;
}

if (i == grid.size() - 1 && j == grid[0].size() - 1)
{
    ans = min(ans, last);
    return;
}
grid[i][j] = 1;
int x[] = {0, 0, 1, 1, 1, -1, -1, -1};
int y[] = {1, -1, 0, 1, -1, 0, 1, -1};
for (int a = 0; a < 8; a++)
{
    if (i + x[a] < grid.size() && i + x[a] > -1 && j + y[a] < grid[0].size() && j + y[a] > -1)
    {
        if (grid[i + x[a]][j + y[a]] == 0)
        {
            dfs(grid, i + x[a], j + y[a], last + 1);
        }
    }
}
return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
    }
    return 0;
}
