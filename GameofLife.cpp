#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fun(vector<vector<int>> &board, vector<vector<int>> &ans, int row, int col)
{
    // var to store the count of neighbour 1's
    int count1 = 0;

    // all possible 8 directions
    int indexes[8][2] = {{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}};

    // go to all 8 directions and store the count of neighbour 1's
    for (int i = 0; i < 8; i++)
    {
        // new position
        int x = row + indexes[i][0];
        int y = col + indexes[i][1];

        // excludingv index out of bound conditions
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
        {
            continue;
        }

        if (ans[x][y] == 1)
        {
            count1++;
        }

        x = row; // backtrack
        y = col; // backtrack
    }

    // any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    if (ans[row][col] == 0 && count1 == 3)
    {
        board[row][col] = 1;
    }
    // under-population.
    else if (ans[row][col] == 1 && count1 == 1 || count1 == 0)
    {
        board[row][col] = 0;
    }
    // over-population.
    else if (ans[row][col] == 1 && count1 > 3)
    {
        board[row][col] = 0;
    }
    // Any live cell with two or three live neighbors lives on to the next generation.
    else if (ans[row][col] == 1 && count1 == 2 || count1 == 3)
    {
        board[row][col] = 1;
    }
}

void gameOfLife(vector<vector<int>> &board, vector<vector<int>> &ans)
{
    // we are taking values in another matrix for checking all the conditions
    // since that board matrix will be updated everytime it will give differemt results
    vector<vector<int>> ans = board;
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // for each index check the 4 conditons
            // if satisfies update
            fun(board, ans, i, j);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    vector<vector<int>> ans = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    gameOfLife(board, ans);
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
