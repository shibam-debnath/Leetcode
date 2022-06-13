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

// * Approach

// 1. take the next element and add the node to it's prev's right side & prev's left is null

// STEPS

// go to the extreme right
// then go to it's left

// declare a node as add with null

// curr node-> right = add;
// curr node->left = NULL;
// add = node;   //! add node stores the next val that needs to be added to it's prev tail

// you are done

class Solution
{
public:
    TreeNode *add = NULL;
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = add;
        root->left = NULL;

        add = root;
    }
};

int main()
{
    // Main function goes here
    return 0;
}