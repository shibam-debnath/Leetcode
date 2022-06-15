// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    // insert all words to v
    void words(string str, vector<string> &v)
    {
        string word;

        stringstream iss(str);

        while (iss >> word)
            v.push_back(word);
    }

    // assign opposite to both char and string
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        unordered_map<string, char> np;

        vector<string> v;
        words(s, v);

        if (pattern.size() != v.size())
        {
            return false;
        }

        int pos = pattern.size();
        
        for (int i = 0; i < pos; i++)
        {
            // mp[char] = string
            mp[pattern[i]] = v[i];
            //np[string] = char
            np[v[i]] = pattern[i];
        }

        for (int i = 0; i < pos; i++)
        {
            if (mp[pattern[i]] != v[i] || np[v[i]] != pattern[i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    // Main function goes here
    return 0;
}
