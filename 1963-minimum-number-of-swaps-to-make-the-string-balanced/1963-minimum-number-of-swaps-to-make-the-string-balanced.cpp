class Solution {
public:
    int minSwaps(string s) {
        int open= 0, close =0;
        stack<char> st;
        for(auto c : s){
            if(c=='[') st.push(c);
            else if(c==']'){
                if(!st.empty()) st.pop();
                else close++;
            }
        }
        
        open = st.size();
        
        int res = open/2;
        if(open%2==0) return res;
        return res+1;
        // cout << open << " " << close << endl;
    }
};