class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size(), res=INT_MAX;
        string s = strs[0];
        
        if(n==0) return "";
        else if(n==1) return s;
        
        int j=0;
        for(int i=1;i<strs.size();i++){
            for(j=0;j<strs[i].size();j++){
                if(s[j]!=strs[i][j]) break;
            }
            s=s.substr(0,j);
        }
        
        return s;
    }
};