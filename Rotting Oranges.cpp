// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
    // Multi source BFS

public:
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
                    q.push({r,
                            c});
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
};

class Solution
{
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    bool NotSafe(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return true;

        return false;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                // starting positions (rotten oranges)
                if (grid[r][c] == 2)
                {
                    q.push({r,
                            c});
                }
            }
        }

        int minutes = 0;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto x = q.front();
                q.pop();

                for (size_t i = 0; i < 4; i++)
                {
                    int newR = x.first + dir[i][0];
                    int newC = x.second + dir[i][1];

                    if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1)
                    {
                        grid[newR][newC] = 2;
                        q.push({newR, newC});
                    }
                }
            }

            minutes++;
        }

        if (fresh_exist(grid))
        {
            return -1;
        }
        else if (minutes == 0)
        {
            // no rotten orange present 
            return 0;
        }
        return minutes - 1;
    }

    bool
    fresh_exist(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] == 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    // Main function goes here
    return 0;
}