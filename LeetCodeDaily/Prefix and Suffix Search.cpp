// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class WordFilter
{
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string> &words)
    {
        // store pre+suff , index of first char in map
        int i = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string p;
            for (int j = 0; j < words[i].size(); j++)
            {
                p += words[i][j];
                string str;
                for (int k = words[i].size() - 1; k >= 0; k--)
                {
                    str += words[i][k];
                    mp[p + "***" + str] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        return mp[prefix + "***" + suffix];
    }
};

int main()
{
    // Main function goes here
    return 0;
}