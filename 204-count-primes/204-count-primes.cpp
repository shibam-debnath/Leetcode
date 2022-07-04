class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        vector<bool> vis(n);
        for(int i=2;i<n;i++){
            if(vis[i]) continue;
            else{
                // cout <<i<<" ";
                ans++;
                for(double j=i+i;j<n;j+=i){
                    vis[j]=true;
                }
            }
        }
        return ans;
        
    }
};