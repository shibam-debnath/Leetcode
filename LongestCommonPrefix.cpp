// Shibam Debnath
// May 23,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

string longestCommonPrefix(vector<string> &strs)
{
    string s = strs[0];
    if (strs.size() == 0)
    {
        return s.substr(0, 0);
    }
    int count = 0;
    for (int i = 1; i < strs.size(); i++)
    {
        for (int k = 0; k < strs[i].size(); k++)
        {
            if (strs[i][k] == s[k])
            {
                count++;
            }
            else if (strs[i][k] != s[k] && k < strs[i].size())
            {
                break;
            }
        }
        s = s.substr(0, count);
        count = 0;
    }

    return s;
}

int main()
{
    // Main function goes here
    return 0;
}