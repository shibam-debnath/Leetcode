// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int start = 0;
        int end = 0;
        int max_len = 0;
        while (end < s.length())
        {
            // if unique insert
            if (mp[s[end]] == 0)
            {
                mp[s[end]]++;
                end++;

                max_len = max(max_len, end - start);
            }
            else
            {
                // we found a duplicate
                //  here what we need to do is that remove all har from map upto the first duplicate element
                // after removing that element we have the rest as unique char

                // a b c d e b
                // if we remove front a & b
                // //a b
                // c d e b
                // we'll have cdeb which has all unique

                mp[s[start]]--;
                start++;
            }
        }

        return max_len;
    }
};

int main()
{
    // Main function goes here
    return 0;
}