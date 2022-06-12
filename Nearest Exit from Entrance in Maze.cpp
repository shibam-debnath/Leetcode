// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int m, n;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> dis;

    int nearestExit(vector<vector<char>> &maze, vector<int> &en)
    {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>> q;

        q.push({en[0], en[1]});
        dis[en[0]][en[1]] = 0;
        while (!q.empty())
        {

            int x = q.front().first;
            int y = q.front().second;

            maze[x][y] = '+';

            q.pop();
            for (int i = 0; i < 4; i++)
            {

                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if (((x1 == 0 || x1 == n - 1) && (y1 >= 0 && y1 < m)) || ((y1 == 0 || y1 == m - 1) && (x1 >= 0 && x1 < n)))

                {
                    if (maze[x1][y1] == '.')
                        return dis[x1][y1];
                }
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && maze[x1][y1] == '.')
                {
                    maze[x1][y1] = '+';
                    q.push({x1, y1});
                    dis[x1][y1] = dis[x][y] + 1;
                }
            }
        }
        return -1;
    }

};

int main()
{
    // Main function goes here
    return 0;
}