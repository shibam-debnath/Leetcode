// Shibam Debnath
// May 24,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int longestValidParentheses(string s)
{
    int n = s.size();

    if (n == 0 || n == 1)
    {
        return 0;
    }
    // we are using stack to store the indexes od brackets
    stack<int> st;

    st.push(-1); // initially if ')' comes then it will handle that

    int ans = 0; // to store req ans

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.size() == 0)
            {
                // if stack is empty and we are getting ")" then keep pushing the index to stack
                // so that stack top becomes that and our calculation i-st.top() gives correct ans
                st.push(i);
            }
            else
            {
                // stores max ans
                // here i-st.top() is the valid parenthesis length
                ans = max(ans, i - st.top());
            }
        }
    }
    return ans;
}
int main()
{
    // Main function goes here
    return 0;
}
