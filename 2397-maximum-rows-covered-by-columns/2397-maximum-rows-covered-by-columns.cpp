class Solution {
public:
    int mx_row = INT_MIN;
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int n=mat.size();
        int m=mat[0].size();
        
        unordered_map<int,bool> mp; // stores which cols to take
        helper(mat,0,cols,mp);
        return mx_row;
    }
    
    void helper(vector<vector<int>>& mat,int pos, int cols,unordered_map<int,bool> &mp){
        int n=mat.size();
        int m=mat[0].size();
        
        // base cases
        if(cols==0){
            // calc max rows 
            int rows = cal_row(mat,mp);
            mx_row = max(mx_row,rows);
            return;
            
        }
        if(pos>=m){
            return;
        }
        
        // pick & not pick concept
        mp[pos] = true;
        helper(mat,pos+1,cols-1,mp); // pick
        mp[pos] = false;
        helper(mat,pos+1,cols,mp); // not pick
    }
    
    int cal_row(vector<vector<int>>& mat,unordered_map<int,bool> &mp){
        int n=mat.size();
        int m=mat[0].size();
        int res = n;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mp[j] and mat[i][j] == 1 ){
                    res--; // remove that row from ans
                    break;
                }
            }
        }
        
        return res;
    }
};