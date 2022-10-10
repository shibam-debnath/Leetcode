class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto w : words) mp[w]++;
        int c=0;
        for(auto m : mp){
            string t = m.first;
            int i=0,j=0;
            while(i<s.size() && j<t.size()){
                if(s[i]==t[j]) i++,j++;
                else i++;
                
                if(j==t.size()) c+=m.second;
            }
        }
        return c;
    }
};