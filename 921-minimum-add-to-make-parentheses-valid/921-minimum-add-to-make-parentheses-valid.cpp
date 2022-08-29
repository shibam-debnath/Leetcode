class Solution {
public:
    int minAddToMakeValid(string s) {
        int open= 0, close =0;
        stack<char> st;
        for(auto c : s){
            
            if(c=='(') st.push(c);
            else if(c==')'){
                if(st.empty()) close++;
                else if(st.top() == '(') st.pop();
                else if(st.top() == ')') close++;
            }
        }
        open = st.size();
        return open+close; 
    }
};