// Shibam Debnath
// June 03,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// for n=0 , ans = 1
// for n=1 , ans = 1
// for n=2 , we have (f0 * f1) + (f1 * f0)  , ans = 2;
// for n=3 , we have(f0 * f2) + (f1 * f1) + (f2 * f0), ans = 5;

// where f0 = no of combination when left / right subtree have 0 numbers
//       f3 = no of combination when left / right subtree have 3 numbers

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int l = 0;
            int r = i - 1;
            while (l <= i - 1)
            {
                dp[i] += dp[l] * dp[r];
                l++;
                r--;
            }
        }

        return dp[n];
    }
};

int main()
{
    // Main function goes here
    return 0;
}