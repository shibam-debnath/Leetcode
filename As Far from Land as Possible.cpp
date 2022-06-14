// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Approach : start dfs from 1's and check the max distance that we can go . NOTE : visisted array ka dhayan rakhke
//            ans is the max distance we can go-1;

class Solution
{
public:
    int dr[4] = {-1, +1, 0, 0};
    int dc[4] = {0, 0, +1, -1};

    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }

        // now start actual bfs
        int distance = 0;
        while (!q.empty())
        {
            int size = q.size();
            distance++;
            while (size--)
            {
                auto v = q.front();
                q.pop();
                // go to all 4 directions and check
                int i = v.first;
                int j = v.second;

                for (size_t k = 0; k < 4; k++)
                {
                    int newR = i + dr[k];
                    int newC = j + dc[k];

                    if (newR < 0 || newC < 0 || newR >= m || newC >= n || grid[newR][newC] != 0)
                    {
                        continue;
                    }
                    // update part
                    grid[newR][newC] = distance;
                    q.push({newR, newC});
                }
            }
        }
        int ans = distance == 1 ? -1 : distance - 1;
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}