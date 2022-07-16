class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        
        int total = m*n;
        
        if(n==r && c==m) return mat;
        
        vector<vector<int>> res(r,vector<int> (c));
        
        int col=0;
        int row=0;
        
        if(r * c != total) return mat;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int val = mat[i][j];
                res[row][col] = val;
                // cout << row << " " << col << endl;
                ++col;
                if(col==c){
                    ++row;
                    col=0;
                }
            }
        }
        
        return res;
    }
};