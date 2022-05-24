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

// Another method - doesn't handle cases where starting withn space 

// string reverseWords(string s)
// {
//     vector<string> v;
//     string str = "";
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == ' ')
//         {
//             v.push_back(str);
//             str = "";
//         }
//         else
//         {
//             str += s[i];
//         }
//     }
//     // since we don't have space afrer last word so we add maually

//     v.push_back(str);

//     string ans;
//     for (int i = v.size()-1; i >=0; i--)
//     {
//         ans += v[i] + " ";
//     }
//     // ans += v[v.size() - 1];

//     return ans;
// }

int main()
{
    string s = "the sky";
    cout << reverseWords(s);
    return 0;
}
