class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int res =0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='(') st.push(i);
            else{
                
                if(i+1<n and s[i+1]==')') i++; // fully atisfies
                
                else if(i == n-1 or s[i+1]!=')') res++; // we need another ) to ssatisfy
                
                if(st.empty()==true) res++;     // wee need (  
                else st.pop();  
            }
        }
        
        int open = st.size();
        return res+open*2; 
    }
};