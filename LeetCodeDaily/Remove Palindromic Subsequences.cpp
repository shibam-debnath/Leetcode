// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool palin(string &s)
    {
        string t = s;
        reverse(t.begin(), t.end());

        return s == t;
    }

    int removePalindromeSub(string s)
    {
        if (s.size() == 0)
        {
            return 0;
        }

        if (palin(s))
        {
            return 1;
        }

        return 2;
    }
};

int main()
{
    // Main function goes here
    return 0;
}