// Shibam Debnath
// June ,2022

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

class Solution
{
public:
    void dfs(TreeNode *root, int t, vector<vector<int>> &ans, vector<int> v)
    {
        // base case
        if (!root)
        {
            return;
        }

        // update target
        v.push_back(root->val);

        // we found a path
        if (!root->left && !root->right && root->val == t)
        {
            ans.push_back(v);
            return;
        }

        dfs(root->left, t - root->val, ans, v);

        dfs(root->right, t - root->val, ans, v);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> v;
        dfs(root, targetSum, ans, v);
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}