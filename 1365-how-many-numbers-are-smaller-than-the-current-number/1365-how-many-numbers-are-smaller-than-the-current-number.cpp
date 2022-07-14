class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int> v = nums;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(mp.find(v[i])!=mp.end()) continue;
            mp[v[i]]=i;
        }
        v.clear();
        for( auto &x : nums){
            int res = mp[x];
            v.push_back(res);
        }
        return v;
    }
};