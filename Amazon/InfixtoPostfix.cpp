/* C++ implementation to convert
infix expression to postfix*/

#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int power(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// checks if char is valid num or letter or not
bool is_num_or_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return true;
    }
    return false;
}

// logic function
string infixToPostfix(string s)
{
    string str = "";

    // stack for the infix to postfix
    stack<char> st;

    // go through all the chars
    for (char c : s)
    {
        // if no or letter
        if (is_num_or_letter(c))
        {
            str.push_back(c);
            // cout << str << "  ";
        }
        // if brackket
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            // closing bracket means insert all operators inside bracket to str
            while (st.top() != '(')
            {
                // keep pushing
                char x = st.top();
                str.push_back(x);
                // cout << str << "  ";
                st.pop();
            }

            // again pop to remove the (
            st.pop();
        }
        // else we have the operators
        else
        {
            // check order and if power kam h jyaada power walo ko peh;le stack se khali kro aur str me ghusao
            // insert to str from stack untill this char operator is powerful
            while (!st.empty() && power(c) <= power(st.top()))
            {
                // Important
                if (c == '^' && st.top() == '^')
                    break;
                else
                {
                    str.push_back(st.top());
                    // cout << str << "  ";
                    st.pop();
                }
            }

            // power jyaada h then push
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack if remaining
    while (!st.empty())
    {
        str.push_back(st.top());
        // cout << str << "  ";
        st.pop();
    }
    return str;
}

// Driver program to test above functions
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(exp) << endl;

    return 0;
}
