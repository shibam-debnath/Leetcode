class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        string a;
        a.push_back(s[0]);
        a.push_back(s[3]);
        int res = stoi(a);
        a.clear();
        a.push_back(s[1]);
        a.push_back(s[2]);
        res+=stoi(a);
        return res;
    }
};