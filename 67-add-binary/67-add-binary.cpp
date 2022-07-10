class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size()-1 , n2 = b.size()-1;
        int carry = 0;
        string res;
        
        int i=n1,j=n2;
        while(i >= 0 || j>=0 || carry>0){
            
            if(i>=0){
                carry+=a[i]-'0';
                i--;
            }
            
            if(j>=0){
                carry+=b[j]-'0';
                j--;
            }
            
            char no = carry%2+'0';
            res.push_back(no);
            carry = carry/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};