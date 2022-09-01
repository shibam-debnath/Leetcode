class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m= mat[0].size();
        
        int startCol = 0;
        int endCol = mat[0].size()-1;
        
        while(startCol <= endCol){
            int mid = startCol+(endCol-startCol)/2;
            
            // now find max element in that col
            
            int maxRow = 0;
            for(int i=1;i<n;i++){
                if(mat[i][mid]>=mat[maxRow][mid]){
                    maxRow = i;
                }
            }
            
            // check if it is greater than it's left and right part or not
            bool GreaterThanLeft = false;
            bool GreaterThanRight = false;
            
            if(mid-1 >= startCol and mat[maxRow][mid] > mat[maxRow][mid-1]){
                GreaterThanLeft = true;
            }
            
            if(mid+1<=endCol and mat[maxRow][mid] > mat[maxRow][mid+1]){
                GreaterThanRight = true;
            }
            
            if(mid==startCol) GreaterThanLeft = true;
            if(mid==endCol) GreaterThanRight = true;
            
            // cout << GreaterThanLeft << " " << GreaterThanRight<< endl;
            
            if(GreaterThanLeft==true and GreaterThanRight==true) return {maxRow,mid};
            else if(GreaterThanLeft==false){
                endCol = mid-1;
            }
            else{
                startCol = mid+1;
            }
        }
        
        return {-1,-1};
        
    }
    
   
};