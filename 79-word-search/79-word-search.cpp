class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool fun(vector<vector<char>> &board, int row, int col, string &word, int i)
    {
        int n = board.size();
        int m = board[0].size();
        
        if(i == word.size()) return true;
    
        if(row <0 or col < 0 or row >= n or col >= m or board[row][col] != word[i] or board[row][col] == '*') return false;

        char c = board[row][col];
        board[row][col] = '*';
        bool a = false;
        for(auto &d : dir){
            
            int x = row+d[0];
            int y = col+d[1];
            a = a or fun(board,x,y,word,i+1);
            
        }
        board[row][col] = c;
        return a;

    }
    
    bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0] && fun(board, i, j, word, 0)) return true;
        }
    }
        
    return false;
        
    }
};