#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fun(vector<vector<int>> &board, vector<vector<int>> &ans, int row, int col)
{
    cout << row << col << endl;
    int count1 = 0;

    int indexes[8][2] = {{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}};

    for (int i = 0; i < 8; i++)
    {
        int x = row + indexes[i][0];
        int y = col + indexes[i][1];

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
        {
            continue;
        }

        if (board[x][y] == 1)
        {
            cout << x << y << "  ";
            count1++;
        }

        x = row;
        y = col;
    }
    cout << endl;

    if (ans[row][col] == 0 && count1 == 3)
    {
        board[row][col] = 1;
    }

    if (ans[row][col] == 1 && count1 == 1)
    {
        board[row][col] = 1;
    }
    if (ans[row][col] == 1 && count1 > 3)
    {
        board[row][col] = 0;
    }
}

void gameOfLife(vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fun(board, ans, i, j);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    gameOfLife(board);
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
