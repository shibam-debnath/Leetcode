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

class Solution
{
public:
    vector<int> v;

    void dfs(TreeNode *root, int height)
    {
        if (!root)
        {
            return;
        }
        if (v.size() == height)
        {
            v.push_back(root->val);
        }

        dfs(root->right, height + 1);

        dfs(root->left, height + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {

        dfs(root, 0);
        return v;
    }
};

int main()
{
    // Main function goes here
    return 0;
}