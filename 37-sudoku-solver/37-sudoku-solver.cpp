class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
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
        for (int x = 0; x <= 8; x++)
            if (board[row][x] == val)
                return false;
        
        for (int x = 0; x <= 8; x++)
            if (board[x][col] == val)
                return false;
        
        int start_row = row - row%3;
        int start_col = col - col%3;
        
        
        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                if(board[start_row+x][start_col+y] == val) return false;
            }
        }
        
        return true;
        
    }

};