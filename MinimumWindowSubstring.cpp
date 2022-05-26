// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

string minWindow(string s, string t)
{
    unordered_map<char, int> mp;

    // storing all p chars in mp
    for (auto &x : t)
    {
        mp[x]++;
    }

    int i = 0, start = 0, j = 0;

    int n = mp.size();

    int mini = INT_MAX;

    for (int i = 0; i < s.size(); i++)
    {
        // remove char's untill all the positions of mp(p wala string) 0 na ho
        mp[s[i]]--;
        if (mp[s[i]] == 0)
        {
            n--;
        }

        // if at any point of time all positons becomes zero that means
        //  we got the first substring
        if (n == 0)
        {
            // ab substring ko aur chota karne ka bari
            // insert karo from begining and if it still shows that n==0 we are getting more smallest length each time
            while (n == 0)
            {
                // update min len
                if ((i - j + 1) < mini)
                {
                    mini = min(mini, i - j + 1);
                    start = j; // it is the starting index of ans substr
                }
                // left se insert krte raho to check if we can make it more smaller or not
                mp[s[j]]++;
                if (mp[s[j]] > 0) // that means it is not the req substr . one char missed . So again start removing other chars untill
                // we get n==0
                {
                    n++;
                }
                // left se age barte rho untill n!=0. it keeps giving us shortest len for n==0
                j++;
            }
        }
    }

    if (mini == INT_MAX)
    {
        return "";
    }
    else
    {
        return s.substr(start, mini);
    }
}

int main()
{
    // Main function goes here
    return 0;
}