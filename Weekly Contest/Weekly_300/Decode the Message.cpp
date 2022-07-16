// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        unordered_map<char, char> mp;

        char ch = 'a';
        for (auto &c : key)
        {
            if (!mp[c] && c != ' ')
            {
                mp[c] = ch++;
            }
        }

        for (auto y : mp)
        {
            cout << y.first << " " << y.second << endl;
        }

        string ans;
        for (char x : message)
        {
            if (x >= 'a' && x <= 'z')
            {
                // cout << x << " " << mp[x] << endl;
                ans.push_back(mp[x]);
            }
            else if (x == ' ')
            {
                ans.push_back(' ');
            }
        }

        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}