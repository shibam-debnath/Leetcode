// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    unordered_map<string, bool> mem;

    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        return check(s1, s2, s3, n1, n2, n3, 0, 0, 0);
    }

    bool check(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3)
    {
        if (p3 == len3)
            return (p1 == len1 and p2 == len2) ? true : false;

        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        if (mem.find(key) != mem.end())
            return mem[key];

        if (p1 == len1)
            return mem[key] = s2[p2] == s3[p3] ? check(s1, s2, s3, len1, len2, len3, p1, p2 + 1, p3 + 1) : false;
        if (p2 == len2)
            return mem[key] = s1[p1] == s3[p3] ? check(s1, s2, s3, len1, len2, len3, p1 + 1, p2, p3 + 1) : false;

        bool one = false, two = false;
        if (s1[p1] == s3[p3])
            one = check(s1, s2, s3, len1, len2, len3, p1 + 1, p2, p3 + 1);
        if (s2[p2] == s3[p3])
            two = check(s1, s2, s3, len1, len2, len3, p1, p2 + 1, p3 + 1);

        return mem[key] = one or two;
    }

    // bool helper(string s1, string s2, string s3, int pos1, int pos2, int pos3, int n1, int n2, int n3)
    // {
    //     // base condition
    //     if (pos3 == n3)
    //         return (pos1 == n1 and pos2 == n2) ? true : false;

    //     string key = to_string(pos1) + "*" + to_string(pos2) + "*" + to_string(pos3);

    //     // memo
    //     if (mp.find(key) != mp.end())
    //         return mp[key];

    //     // logic for recursion

    //     if (pos1 == n1)
    //         return mp[key] = s2[pos2] == s3[pos3] ? helper(s1, s2, s3, n1, n2, n3, pos1, pos2 + 1, pos3 + 1) : false;
    //     if (pos2 == n2)
    //         return mp[key] = s1[pos1] == s3[pos3] ? helper(s1, s2, s3, n1, n2, n3, pos1 + 1, pos2, pos3 + 1) : false;

    //     // cases when eithe s1 completely ends
    //     // if (pos1 == n1)
    //     //     if (s2[pos2] == s3[pos3])
    //     //         return mp[key] = helper(s1, s2, s3, pos1, pos2 + 1, pos3 + 1, n1, n2, n3);
    //     //     else
    //     //         return false;

    //     // // cases when eithe s2 completely ends
    //     // if (pos2 == n2)
    //     //     if (s1[pos1] == s3[pos3])
    //     //         return mp[key] = helper(s1, s2, s3, pos1 + 1, pos2, pos3 + 1, n1, n2, n3);
    //     //     else
    //     //         return false;

    //     // rest of the cases
    //     bool str1 = false, str2 = false;

    //     if (s1[pos1] == s3[pos3])
    //         str1 = helper(s1, s2, s3, pos1 + 1, pos2, pos3 + 1, n1, n2, n3);

    //     if (s2[pos2] == s3[pos3])
    //         str2 = helper(s1, s2, s3, pos1, pos2 + 1, pos3 + 1, n1, n2, n3);

    //     return mp[key] = str1 or str2;
    // }
};

class Solution
{
public:
    int t[201][201];
    bool util(string s1, string s2, string s3, int i, int j, int k)
    {
        if (k >= s3.size())
            return true;

        if (t[i][j] != -1)
            return t[i][j];

        if (s1[i] == s3[k] && s2[j] == s3[k] && i < s1.size() && j < s2.size())
            return t[i][j] = util(s1, s2, s3, i + 1, j, k + 1) || util(s1, s2, s3, i, j + 1, k + 1);

        else if (s1[i] == s3[k] && i < s1.size())
            return t[i][j] = util(s1, s2, s3, i + 1, j, k + 1);

        else if (s2[j] == s3[k] && j < s2.size())
            return t[i][j] = util(s1, s2, s3, i, j + 1, k + 1);

        else
            return t[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 + n2 != s3.size())
            return false;

        memset(t, -1, sizeof(t));
        return util(s1, s2, s3, 0, 0, 0);
    }
};

int main()
{
    // Main function goes here
    return 0;
}