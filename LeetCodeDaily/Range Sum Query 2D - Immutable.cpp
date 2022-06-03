// Shibam Debnath
// June 03,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class NumMatrix
{
public:
    vector<vector<long>> dp;

    NumMatrix(vector<vector<int>> &M)
    {

        // prefix sum of the matrix in dp matrix
        dp.resize(M.size() + 1, vector<long>(M[0].size() + 1, 0));

        for (int i = 1; i < M.size() + 1; i++)
        {
            for (int j = 1; j < M[0].size() + 1; j++)
            {
                dp[i][j] = M[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
    }

    // venn diagram concept of matrix

    // re area = a-b-c+d;

    int sumRegion(int R1, int C1, int R2, int C2)
    {

        return (int)(dp[R2 + 1][C2 + 1] - dp[R2 + 1][C1] - dp[R1][C2 + 1] + dp[R1][C1]);
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main()
{
    // Main function goes here
    return 0;
}