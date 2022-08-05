class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m= colSum.size();
        vector<vector<int>> res(n,vector<int> (m,0));
        
        for(int i=0;i<rowSum.size();i++){
            for(int j=0;j<colSum.size() and rowSum[i]>0;j++){
                res[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i]-=res[i][j];
                colSum[j]-=res[i][j];
            }
        }
        return res;
    }
};