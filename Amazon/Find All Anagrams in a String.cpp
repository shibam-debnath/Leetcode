// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        vector<int> ans; // to store the answers
        int s_len = s.size();
        int p_len = p.size();

        // edge cases
        if (p_len > s_len)
            return ans;

        unordered_map<char, int> mp, np;

        for (int i = 0; i < p_len; i++)
        {
            mp[s[i]]++;
            np[p[i]]++;
        }

        int start = 0;
        // use sliding window of size p_len to check in s if it has all the elements
        for (int i = p_len; i <= s_len; i++)
        {

            if (ana(mp, np))
            {
                ans.push_back(start);
            }
            mp[s[i]]++;
            mp[s[start]]--;
            start++;
        }

        return ans;
    }

    // use original string but copy of map
    bool ana(unordered_map<char, int> &mp, unordered_map<char, int> &np)
    {
        for (auto it : np)
        {
            if (it.second != mp[it.first])
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