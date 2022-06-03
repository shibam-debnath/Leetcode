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

int sumOfLeftLeaves(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }

    if (root->left && root->left->left == NULL && root->left->right == NULL)
    {
        return root->left->val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }

    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

    return 0;
}

int main()
{
    // Main function goes here
    return 0;
}