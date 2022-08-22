// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Function to find the smallest window in the string s consisting
// of all the characters of string p.
string smallestWindow(string s, string p)
{
    unordered_map<char, int> mp;

    // storing all p chars in mp
    for (auto &x : p)
    {
        mp[x]++;
    }

    int i = 0, start = 0, j = 0;
    int n = mp.size();
    int mi = INT_MAX;
    while (i < s.size())
    {
        // remove char's which are repeating
        mp[s[i]]--;
        if (mp[s[i]] == 0)
        {
            n--;
        }

        // if at any point of time mp size becomes 0
        if (n == 0)
        {
            while (n == 0)
            {
                if ((i - j + 1) < mi)
                {
                    // length of min sliding window
                    mi = min(mi, i - j + 1);
                    // update start position
                    start = j;
                }
                // after the first sli.win. we'll start pushing next elements (//!not only p string).
                // if the elements are not in p then mp.size or n != 0
                // if we any element in s which is in p then n = 0  -> we have to update sliding window

                mp[s[j]]++;
                if (mp[s[j]] > 0)
                {
                    n++;
                }

                // keep increasing k
                j++;
            }
        }
        i++;
    }

    if (mi == INT_MAX)
    {
        return "-1";
    }
    else
    {
        return s.substr(start, mi);
    }
}

int main()
{
    // Main function goes here
    return 0;
}