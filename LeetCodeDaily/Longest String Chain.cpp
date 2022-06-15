// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    static bool cmp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string> &words)
    {
        int ans = 1;
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), cmp);
        for (auto curr_word : words)
        {
            mp[curr_word] = 1;
            // try removing one element from each position and check if it is already present int the map.
            // if present that means it is a aprt of chain so increment prev counter
            for (int j = 0; j < curr_word.size(); j++)
            {
                string prev_str = curr_word.substr(0, j) + curr_word.substr(j + 1);
                if (mp[prev_str])
                {
                    mp[curr_word] = mp[prev_str] + 1;
                    ans = max(ans, mp[curr_word]);
                }
            }
        }
        return ans;
    }
};
// done
int main()
{
    // Main function goes here
    return 0;
}