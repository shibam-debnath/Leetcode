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
int height(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);

    if (abs(h1 - h2) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    // Main function goes here
    return 0;
}