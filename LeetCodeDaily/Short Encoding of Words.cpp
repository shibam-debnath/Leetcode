// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    static bool comp(string &s1, string &s2)
    {
        return s1.size() > s2.size();
    }

    int minimumLengthEncoding(vector<string> &words)
    {
        // edge cases

        if (words.size() == 1)
        {
            return words[0].size() + 1;
        }

        // for the approach to work we need to sort words on the basis of len first and reverse the strings so that we can use substr property
        sort(words.begin(), words.end(), comp);

        // logic
        int ans = 0;
        unordered_map<string, int> mp; // string , length store

        for (auto s : words)
        {
            int len = s.size();
            // if new string is already there in th map
            if (mp.find(s) != mp.end())
            {
                // then don't increment the length
            }
            else
            {
                // if unique keep increasing char num , if not unique from last  then remove the count
                len++; // for the #
                ans += len;

                // finally store the new unique string to map also
                string str = "";
                for (int i = len - 1; i >= 0; i--)
                {
                    str = s.substr(i);
                    // str.push_back(s[i]);
                    // store this string to map
                    cout << str << "  ";
                    mp[str] = len - i; // length is len - i;
                }
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