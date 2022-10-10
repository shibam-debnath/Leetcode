class Solution {
    public int[][] restoreMatrix(int[] r, int[] c) {
        int n= r.length; int m = c.length;
        int [][] res = new int[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m  && r[i]>0;j++){
                res[i][j] = Math.min(r[i],c[j]);
                r[i]-=res[i][j];
                c[j]-=res[i][j];
            }
        }
        return res;
    }
}