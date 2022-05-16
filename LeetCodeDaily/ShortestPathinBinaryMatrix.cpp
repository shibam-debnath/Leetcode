#include <bits/stdc++.h>
using namespace std;
#define ll long long
queue<pair<int, int>> q;
vector<vector<int>> dir;
bool isSafe(vector<vector<int>> &grid, int x, int y)
{

    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0)
        return true;
    return false;
}

int calc(int row, int col, vector<vector<int>> &grid)
{
    if (row == 0 && col == 0)
    {
        return grid[0][0];
    }

    while (!q.empty())
    {
        auto x = q.front();
        // q.pop();

        // current posi se har direction mein check karo if 0 is there
        if (isSafe(grid, row - 1, col - 1))
        {
            q.push({row - 1, col - 1});
            grid[row - 1][col - 1] = 1 + grid[row][col];
        }
        else if (isSafe(grid, row - 1, col))
        {
            grid[row - 1][col] = 1 + grid[row][col];
            q.push({row - 1, col});
        }
        else if (isSafe(grid, row, col - 1))
        {
            grid[row][col - 1] = 1 + grid[row][col];
            q.push({row, col - 1});
        }
        else
        {
            grid[row][col] = -1;
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
