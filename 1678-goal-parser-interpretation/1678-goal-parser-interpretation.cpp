class Solution {
public:
    string interpret(string c) {
        int i=0;
        int n=c.size();
        string ans;
        while(i<n){
            
            if(c[i]=='G') ans.push_back('G');  
            
            else if(c[i]=='('){
                i++;
                if(c[i]==')') ans.push_back('o');
                else{
                    ans+="al";
                    i+=2;
                }
            }
            i++;
        }
        return ans;
    }
};