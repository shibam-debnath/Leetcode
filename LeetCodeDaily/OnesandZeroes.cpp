// Shibam Debnath
// May 23,2022

// ** Question

// You are given an array of binary strings strs and two integers m and n.
// Return the size of the largest subset of strs such that there are at most m 0's and
// n 1's in the subset.
// A set x is a subset of a set y if all elements of x are also elements of y.

// ! Ans
// ** tabulation

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int findMaxForm(vector<string> &s, int m, int n)
{
    int c0 = 0, c1 = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (auto &si : s)
    {
        // we are calculating count of 1 and 0 for each string
        for (auto &x : si)
        {
            if (x == '1')
            {
                c1++;
            }
            else
            {
                c0++;
            }
        }
        // dp table

        for (int i = m; i >= c0; i--)
        {
            for (int j = n; j >= c1; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1);
            }
        }

        c0 = 0;
        c1 = 0;
    }
    return dp[m][n];
}

// ** Memoized version

// int func(vector<vector<int>> &dp, vector<string> &s, int i, int m, int n)
// {

// if (m == 0 || n == 0 || i == s.size())
// {
//     return 0;
// }

// if (dp[m][n] != -1)
// {
//     return dp[m][n];
// }

// int c0 = 0, c1 = 0;
// for (auto x : s[i])
// {
//     if (x == '1')
//     {
//         c1++;
//     }
//     else
//     {
//         c0++;
//     }
// }

// if (c0 <= m && c1 <= n)
// {
//     return dp[n][m] = max(1 + func(dp, s, i + 1, m - c0, n - c1), func(dp, s, i + 1, m, n));
// }
// else
// {
//     return dp[n][m] = func(dp, s, i + 1, m, n);
// }

//     int c0 = 0, c1 = 0;
//     for (auto &si : s)
//     {
//         // we are calculating count of 1 and 0 for each string
//         for (auto &x : si)
//         {
//             if (x == '1')
//             {
//                 c1++;
//             }
//             else
//             {
//                 c0++;
//             }
//         }

//         // dp table
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//         for (int i = m; i >= c0; i--)
//         {
//             for (int j = n; j >= c1; j--)
//             {
//                 dp[m][n] = max(1 + dp[i - c0][j - c1], dp[i][j]);
//             }
//         }
//     }

//     return dp[0][0];
// }

// int findMaxForm(vector<string> &s, int m, int n)
// {
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//     int i = 0;
//     int c0 = 0;
//     int c1 = 0;
//     return func(dp, s, i, m, n);
// }

int main()
{
    // Main function goes here
    return 0;
}