// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dr[4] = {-1, +1, 0, 0};
int dc[4] = {0, 0, +1, -1};

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;

    int frsh = 0; // fresh oranges count
    int ans = 0;

    for (int r = 0; r < m; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            // starting positions (rotten oranges)
            if (grid[r][c] == 2)
            {
                q.push({r, c});
            }
            else if (grid[r][c] == 1)
            {
                frsh++;
            }
        }
    }
    while (frsh != 0 && !q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto x = q.front();
            q.pop();

            for (size_t i = 0; i < 4; i++)
            {
                int newR = x.first + dr[i];
                int newC = x.second + dc[i];

                if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1)
                {
                    grid[newR][newC] = 2;
                    q.push({newR,
                            newC});
                    frsh--;
                }
            }
        }

        ans++;
    }

    if (frsh > 0)
        return -1;

    return ans;
}

// shortest path 8 directions

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> pq;

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }

        pq.push(make_pair(0, 0));
        // all possible dirs are included here
        int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
        int dy[8] = {0, 1, 0, -1, -1, -1, 1, 1};

        int newcol = 0;
        int newrow = 0;

        grid[0][0] = 1;

        while (!pq.empty())
        {
            int row = pq.front().first;
            int col = pq.front().second;

            if (row == n - 1 && col == n - 1)
            {
                return grid[row][col];
            }

            // iterate for all 8 dirs
            for (int i = 0; i < 8; i++)
            {
                newrow = row + dx[i];
                newcol = col + dy[i];

                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n && grid[newrow][newcol] == 0)
                {
                    pq.push(make_pair(newrow, newcol));
                    grid[newrow][newcol] = grid[row][col] + 1;
                }
            }

            pq.pop();
        }
        return -1;
    }
};

int main()
{
    // Main function goes here
    return 0;
}