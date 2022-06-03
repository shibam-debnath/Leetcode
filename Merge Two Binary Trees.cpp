// Shibam Debnath
// June 02,2022

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

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    // Base cases
    if (!root2)
    {
        return root1;
    }
    else if (!root1)
    {
        return root2;
    }

    root1->val = root1->val + root2->val;

    // if root 2 exists then only add that values to root1 else ignore

    // if root2.left exists then add val to root1 else ignore
    if (root2->left)
    {
        root1->left = mergeTrees(root1->left, root2->left);
    }
    // if root2.right exists then add val to root1 else ignore
    if (root2->right)
    {
        root1->right = mergeTrees(root1->right, root2->right);
    }

    return root1;
}

int main()
{

    // Main function goes here
    return 0;
}