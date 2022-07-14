class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp,np;
        for(auto &w : words1){
            mp[w]++;
        }
        for(auto &v : words2){
            np[v]++;
        }
        int res=0;
        for(auto m : mp){
            if(m.second==1){
                string s = m.first;
                if(np.find(s)!=np.end() && np[s]==1) res++;
            }
        }
        return res;
    }
};