// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int calculate(string s)
{
    char op = '+';
    int no = 0;
    // we can add any char =,-,*,/

    // it is because we are applying a operation on a prev stored no whenever we
    // are getting + or - or * or /. so this will help to occur the last operation
    s = s + '-';
    int ans = 0;
    // stack to store sum at each step
    stack<int> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            no = no * 10 + (s[i] - '0');
        }
        // ignore spaces 
        else if (s[i] == ' ')
            continue;
        
        else if (op == '+' || op == '-' || op == '*' || op == '/')
        {
            if (op == '+')
            {
                st.push(no);
            }
            else if (op == '-')
            {
                st.push(-no);
            }
            else
            {
                int num;
                if (op == '*')
                    num = st.top() * no;
                else
                    num = st.top() / no;
                st.pop();
                st.push(num);
            }

            // most important part every time we are getting a char we are applying the previously stored
            // operation and after operation we are updating the operation
            op = s[i];
            // update no also
            no = 0;
        }
    }


    // finally cumulative sum of stack values gives ans
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}
int main()
{
    // Main function goes here
    return 0;
}