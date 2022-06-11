// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<char>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == '0')
    {
        return;
    }
    grid[i][j] = '0';

    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}


//...
//...same given code... using this method
//...

vector<int> dx{0, -1, 0, 1, 0};
// vector<vector<int>> h;
// int m = h.size(), n = h[0].size();
// for (int i = 0; i < 4; i++)
// {
//     int nx = x + dx[i], ny = y + dx[i + 1];
//     if (nx < 0 || nx >= m || ny < 0 || ny >= n || h[nx][ny] < h[x][y])
//         continue;

//     dfs(nx, ny, visited, h);
// }

int main()
{
    // Main function goes here
    return 0;
}