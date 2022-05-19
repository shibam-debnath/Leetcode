// Shibam Debnath
// May 19,2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool fun(vector<vector<char>> &board, int row, int col, string word[], int i)
{

    if (i == word.length() - 1)
    {
        return true;
    }

    return fun(board, row, col, word, i + 1)

        fun(board, i, j, word, i + 1)
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0] && fun(board, i, j, word, 0))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
