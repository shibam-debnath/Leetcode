// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
};

class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &vals)
    {
        if (root == NULL)
            return;

        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    bool isSorted(vector<int> &v)
    {
        for (int i = 0; i < v.size() - 1; ++i)
        {
            if (v[i + 1] <= v[i])
                return false;
        }
        return true;
    }
};

int main()
{
    // Main function goes here
    return 0;
}