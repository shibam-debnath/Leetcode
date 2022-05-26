// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int romanToInt(string s)
{
    unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

    int ans = 0;
    for(int i = 0; i < s.size() - 1; i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            ans = ans - mp[s[i]];
        }
        else
        {
            ans += mp[s[i]];
        }
    }

    ans += mp[s[s.size() - 1]];

    return ans;
}
int main()
{
    // Main function goes here
    return 0;
}