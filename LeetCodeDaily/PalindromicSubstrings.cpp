// Shibam Debnath
// May 21,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int countSubstring(string s)
{
    int n = s.size();
    int c = n; // since each char is a palindrome
    int l = 0, r = 0;
    // for odd sized substrings
    for (int i = 1; i < n; i++)
    {
        l = i - 1;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            c++;
            l--;
            r++;
        }
    }
    // for even sized substrings
    for (int i = 1; i < n; i++)
    {
        l = i - 1;
        r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            c++;
            l--;
            r++;
        }
    }

    return c;
}

int main()
{
    // Main function goes here
    string s = {a, b, c};
    cout << countSubstring(s);
    return 0;
}