class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int> res(s.size());
        for(int i=0;i<s.size();i++){
            int op=0;
            for(int j=0;j<i;j++){
                if(s[j]=='1') op+=abs(i-j);
            }
            for(int k=i+1;k<s.size();k++){
                if(s[k]=='1') op+=abs(i-k);
            }
            res[i] = op;
        }
        return res;
    }
};