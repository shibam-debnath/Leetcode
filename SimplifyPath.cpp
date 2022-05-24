// Shibam Debnath
// May 23,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

string simplifyPath(string s)
{
    int n = s.size();
    stack<string> st;
    for (int i = 0; i < n; i++)
    {
        // we'll ignor "/" and store string upto nxt "/"
        if (s[i] == '/')
        {
            continue;
        }
        // initialize an empty string to store paths
        string a;
        while (i < s.size() && s[i] != '/')
        {
            a += s[i];
            i++;
        }

        if (a == ".")
        {
            continue;
        }
        else if (a == "..")
        {
            // if string s is ".." then pop() it from stack
            if (!st.empty())
                st.pop();
        }
        else
        {
            st.push(a);
        }
    }

    string ans;

    while (!st.empty())
    {
        ans = "/" + st.top() + ans;   // main formula
        st.pop();
    }

    if (ans.size() == 0)
        return "/";

    return ans;
}

int main()
{
    // Main function goes here
    return 0;
}