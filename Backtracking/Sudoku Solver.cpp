// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        int n = board.size();

        solve(board, 0, 0);
    }

    bool solve(vector<vector<char>> &board, int row, int col)
    {

        if (row == 9)
            return true;
        if (col == 9)
            return solve(board, row + 1, 0);
        if (board[row][col] != '.')
            return solve(board, row, col + 1);

        for (char c = '1'; c <= '9'; c++)
        {
            if (Valid_pos(board, row, col, c))
            {
                board[row][col] = c;
                if (solve(board, row, col + 1))
                    return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    bool Valid_pos(vector<vector<char>> &board, int row, int col, char val)
    {
        return safe_row(board, row, val) || safe_col(board, col, val) || safe_box(board, row, col, val);
    }

    bool safe_col(vector<vector<char>> &board, int row, char val)
    {
        for (int x = 0; x <= 8; x++)
            if (board[row][x] == val)
                return false;
        return true;
    }

    bool safe_row(vector<vector<char>> &board, int col, char val)
    {
        for (int x = 0; x <= 8; x++)
            if (board[x][col] == val)
                return false;
        return true;
    }

    bool safe_box(vector<vector<char>> &board, int row, int col, char val)
    {
        int startRow = row - row % 3, startCol = col - col % 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i + startRow][j + startCol] == val)
                    return false;

        return true;
    }
};

int main()
{
    // Main function goes here
    return 0;
}