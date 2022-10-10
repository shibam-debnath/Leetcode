class Solution {
public:
    bool isPalindrome(string s) {
        
        if(s.size()==1) return true;
        
        int left=0,right=s.size()-1;
        
        while(left<right){
            
            if(isalnum(s[left])==false) left++;
            else if(isalnum(s[right])==false) right--;
            
            else if(tolower(s[left])!=tolower(s[right])) return false;

            else {
                left++;right--;
            }
        }
        
        return true;
    }
};