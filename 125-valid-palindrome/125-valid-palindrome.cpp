class Solution {
public:
    bool isPalindrome(string s) {
        
        if(s.size()==1) return true;
        
        string str="";
        
        for(auto &c : s){
            
            //uppercse to lower
            if(c>='A' && c <='Z'){
                char low = c | ' ';
                // cout << low << " ";
                str.push_back(low);
            }
            else if(c>='a' && c <='z' || isalnum(c)){
                str.push_back(c);
            }
        }
        
        if(str.size()==0 || str.size()==1 ) return true;
        
        string rev=str;
        reverse(rev.begin(),rev.end());
        
        return rev==str;
    }
};