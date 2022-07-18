class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        
        // STEP 01 : prefix sum
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        
        int res=0;
        
        // STEP 02 : for every pair of column perform operation - subarray sum technique with 
        //           with sliding window to get every apir of column
        for(int c1=0;c1<m;c1++){
            for(int c2=c1;c2<m;c2++){
                
                // since we handled every column pair now work on operation on every rows
                // subarray sum equals k technique
                int sum=0;
                unordered_map<int,int> mp;
                mp[0]=1;
                
                for(int row=0;row<n;row++){
                    
                    sum+=mat[row][c2];
                    
                    // remove extra left part(search space) if there 
                    if(c1>0) sum-=mat[row][c1-1];
                    
                    int srch = sum-target;
                    
                    if(mp.find(srch)!=mp.end()) res += mp[srch];
                    
                    mp[sum]++;
                }
            }
        }
        
        return res;
    }
};