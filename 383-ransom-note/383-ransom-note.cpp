class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp,np;
        for(auto x : magazine) mp[x]++;
        for(auto x : ransomNote) np[x]++;
        
        for(auto &x : ransomNote){
            if(!mp.count(x)) return false;
            if(np[x]>mp[x]) return false;
        }
        return true;
    }
};