class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() and s[i]==' ')i++;
        bool neg = false;
        if(s[i]=='-' or s[i]=='+'){
            if(s[i]=='-'){
                neg = true;
            } 
            i++;
        }
        
        long long res =0;
        cout << INT_MIN << " " << INT_MAX ;
        while(i<s.size() and isdigit(s[i])){
            int n = s[i]-'0';
            res=res*10+n;
            if(res>INT_MAX) return neg==true?-INT_MAX-1:INT_MAX;
            if(res<INT_MIN) return neg==true?-INT_MIN:INT_MIN-1;
            i++;
        }
        if(neg==true) return -res;
        return res;
    }
};