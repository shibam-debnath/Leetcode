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
    bool same(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
        {
            return true;
        }

        if (!left || !right || left->val != right->val)
        {
            return false;
        }

        return same(left->left, right->right) && same(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        return same(root->left, root->right);
    }
};

int main()
{
    // Main function goes here
    return 0;
}