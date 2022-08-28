class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
            sorrt(mat,i,0);
        }
        for(int i=1;i<mat[0].size();i++){
            sorrt(mat,0,i);
        }
        return mat;
    }
    
    void sorrt(vector<vector<int>>& mat,int r,int c){
        int n=mat.size();
        int m=mat[0].size();
        
        int i= r , j =c;
        vector<int> nums;
        while(i<n and j<m){
            nums.push_back(mat[i][j]);
            i++;j++;
        }
        sort(nums.begin(),nums.end());
        
        int k=0;
        i=r;
        j=c;
        
        while(i<n and j<m and k<nums.size()){
            mat[i][j] = nums[k];
            i++;j++;k++;
        }
    }
};