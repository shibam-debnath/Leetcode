// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    int dr[4] = {-1, +1, 0, 0};
    int dc[4] = {0, 0, +1, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q; // to store index this time
        // first we push all our starting nodes to queue
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (mat[r][c] == 0)
                {            
                    q.emplace(r, c); // starting nodes from where we'll calculate min distance
                }
                else
                {
                    mat[r][c] = -1; // Marked as -1 as of now . we'll store min distances here
                }
            }
        }

        // now start actual bfs

        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            // go to all 4 directions and check
            for (size_t i = 0; i < 4; i++)
            {
                int newR = x.first + dr[i]; // here x contains the coordinates of starting/parent node/old node
                int newC = x.second + dc[i];
                // if visited skip && skip invalid cases // not -1 means we have already visited
                if (newR < 0 || newC < 0 || newR >= m || newC >= n || mat[newR][newC] != -1)
                {
                    continue;
                }

                // update part
                mat[newR][newC] = 1 + mat[x.first][x.second];
                q.push({newR, newC});
            }
        }

        return mat;
    }
};
int main()
{
    // Main function goes here
    return 0;
}