class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for(auto x : encoded){
            int n = x^first;
            ans.push_back(n);
            first=x^first;
        }
        return ans;
    }
};