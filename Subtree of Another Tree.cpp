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

bool Same(TreeNode *a, TreeNode *b)
{
    if (a == NULL && b == NULL)
    {
        return true;
    }
    else if (a == NULL || b == NULL)
    {
        return false;
    }

    if (a->val != b->val)
    {
        return false;
    }

    return Same(a->left, b->left) && Same(a->right, b->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!root)
    {
        return false;
    }

    // if both the trees have same val and are same then only we'll return true else we'll check for other nodes
    if (root->val == subRoot->val && Same(root, subRoot))
    {
        return true;
    }

    // if root is not same with subRoot then check left or right nodes of tree & compare with subRoot
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    // Main function goes here
    return 0;
}