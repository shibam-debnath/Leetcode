// Shibam Debnath
// May 23,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Runtime: 3 ms, faster than 84.10% of C++ online submissions for Generate Parentheses.
// Memory Usage: 15.5 MB, less than 24.46% of C++ online submissions for Generate Parentheses

void generate(string s, int l, int r, vector<string> &ans)
{

    if (l == 0 && r == 0)
    {
        ans.push_back(s);
        return;
    }

    if (l > 0)
    {
        s.push_back('(');
        generate(s, l - 1, r, ans);
        s.pop_back();
    }

    if (r > 0 && r > l)
    {
        s.push_back(')');
        generate(s, l, r - 1, ans);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string s="";
    generate(s, 0, 0, ans);
}
int main()
{
    // Main function goes here
    return 0;
}