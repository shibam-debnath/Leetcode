class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>> mp;
        
        for(auto &x : logs){
            mp[x[0]].insert(x[1]);
        }
        
        vector<int> res(k,0);
        
        for(auto &m : mp){
            res[m.second.size()-1]++;
        }
        
        return res;
    }
};