class Solution {
public:
    int firstUniqChar(string s) {
    unordered_map<char,int> mp,np;
    for (int i=s.size()-1;i>=0;i--)
    {
        mp[s[i]]++;
        np[s[i]]=i;
    }
    for (auto &m : mp)
    {
        if(m.second==1){
            char c=m.first;
            return np[c];
        } 
    }
    
    return -1;
    }
};