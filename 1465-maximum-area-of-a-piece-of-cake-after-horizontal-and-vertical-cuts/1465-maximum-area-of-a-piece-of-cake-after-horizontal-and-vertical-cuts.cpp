class Solution {
public:
    int maxArea(int height, int width, vector<int>& h, vector<int>& v) {
        long long row=0,col=0;
        long long mod=1000000007,ans=0;
        
        // row
        sort(h.begin(),h.end());
        for(int i=1;i<h.size();i++){
            long long diff = h[i]-h[i-1];
            row = max(row,diff);
        }
        // edge cases for row
        row =max(row,(long long)h[0]-0);
        row= max(row,(long long)height-h[h.size()-1]);
        
        // col 
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            long long diff = v[i]-v[i-1];
            col=max(col,diff);
        }
        // edge cases for row
        col =max(col,(long long)v[0]-0);
        col = max(col,(long long)width-v[v.size()-1]);
        
        // cout << row << "  " << col << endl;
        ans= (row*col)%mod;
        return ans;
    }
};