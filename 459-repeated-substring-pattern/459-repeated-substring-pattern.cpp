class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        
        for(int i=1;i<n;i++){
            if(n%i==0){
                string str = s.substr(0,i);
                int j=i;
                bool res=true;
                while(j<n){
                    if(s.substr(j,i)!=str) res= 0;
                    j+=i;
                }
                if(res) return true;
            }
        }
        return false;
    }
};