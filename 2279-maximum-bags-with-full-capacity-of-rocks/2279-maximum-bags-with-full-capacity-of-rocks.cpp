class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n =rocks.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = capacity[i]-rocks[i];
        }
        sort(v.begin(),v.end());
        
        int res=0;
        
        for(auto x : v){
            // cout << x << " ";
            if(additionalRocks-x >= 0){
                res++;
                additionalRocks-=x;
            }
            else{
                return res;
            }
        }
        return res;
    }
};