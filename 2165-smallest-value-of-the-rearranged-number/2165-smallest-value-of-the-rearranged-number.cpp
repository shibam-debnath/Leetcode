class Solution {
public:
    long long smallestNumber(long long num) {
    
        string s = to_string(num);
    
        if(num>0 ){
            sort(s.begin(),s.end());
            int i=0;
            while(s[i]=='0') i++;{
                swap(s[0],s[i]);
            }
            return stoll(s);
        }
        sort(s.begin(),s.end(),greater<char> ());
        return -stoll(s);
    }
};