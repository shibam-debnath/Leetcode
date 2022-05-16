//Shibam Debnath
//May,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

    int newcol=0;
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
        for (int i = 0; i < 8;i++)
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

    
  
