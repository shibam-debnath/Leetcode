// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//! Recursion

vector<vector<int>> dp;
int findd(string s, string t, int n, int m, int i, int j)
{

    if (j == m)
    {
        return 1;
    }

    if (i == n)
    {
        return 0;
    }

    // choice diagram

    if (s[i] == t[j])
    {

        return findd(s, t, n, m, i + 1, j + 1) + findd(s, t, n, m, i + 1, j);
    }
    else
    {
        return findd(s, t, n, m, i + 1, j);
    }
}

int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    return findd(s, t, n, m, 0, 0);
}

//! MEMOIZATION

vector<vector<int>> dp;
int findd(string s, string t, int n, int m, int i, int j)
{
    // base case
    // 1. when our t string becomes empty i.e t="" , we got our one sol so ret 1
    if (j == m)
    {
        return 1;
    }
    // 2 when s becomes empty first and t is not empty then it is not possible t0o get that t from that s
    if (i == n)
    {
        return 0;
    }

    // memoization
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // choice diagram

    // if s[i]==t[j] we have two choices either move both si and tj or only move s[i]
    // else  move s[i] only
    if (s[i] == t[j])
    {
        // taking both si and tj                  //taking only s[i]
        return dp[i][j] = findd(s, t, n, m, i + 1, j + 1) + findd(s, t, n, m, i + 1, j);
    }
    else
    {
        return dp[i][j] = findd(s, t, n, m, i + 1, j);
    }
}
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    dp.resize(n, vector<int>(m, -1));
    return findd(s, t, n, m, 0, 0);
}

// ! Tabulation
int numDistinct(string s, string t)
{
    int m = t.length(), n = s.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j = 0; j <= n; j++)
        dp[0][j] = 1;
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= m; i++)
            dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0); // 0 since we are already adding left wala
    return dp[m][n];
}

// Further optimization

int numDistinct(string s, string t)
{
    int m = t.length(), n = s.length();
    vector<unsigned long long> cur(m + 1, 0);
    cur[0] = 1;
    for (int j = 1; j <= n; j++)
    {
        int pre = 1;
        for (int i = 1; i <= m; i++)
        {
            // cur[i] == dp[i-1][j] i.e. left wala
            int temp = cur[i];
            cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? pre : 0);
            // pre = dp[i-1][j-1] i.e. left top
            pre = temp;
        }
    }
    return cur[m];
}

int main()
{
    // Main function goes here
    return 0;
}
