class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (!next_permutation(s.begin(), s.end())) return -1;
        
        long long ans =0;
        ans=stoll(s);
        if(ans>INT_MAX) return -1;
        return ans;
    }
};