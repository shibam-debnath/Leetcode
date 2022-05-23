// Shibam Debnath
// May 23,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

string reverseWords(string s)
{
    int i = 0;
    string t;
    int j = 0;
    int n = s.size();
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        j = i;
        while (j < n && s[j] != ' ')
            j++;
        t = " " + s.substr(i, j - i) + t;
        i = j + 1;
    }

    i = 0;
    while (i < n && t[i] == ' ')
        i++;
    // string will start from ith position
    t = t.substr(i);

    return t;
}

int main()
{
    string s = "the sky";
    cout << reverseWords(s);
    return 0;
}
