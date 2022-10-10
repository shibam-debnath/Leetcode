class Solution {
public:
    bool present(string &s ,unordered_map<char,int> mp){
        for(auto &c : s){
            if(mp.find(c)==mp.end() || mp[c]==0){
                return false;
            }
            // mil gaya so remove
            mp[c]--;
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        unordered_map<char,int> mp;
        for(auto &c : chars){
            mp[c]++;
        }
        
        for(auto &s : words){
            if(present(s,mp)){
                ans+=s.size();
            }
        }
        
        return ans;
    }
};