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
    int ans = INT_MAX;
    int val = -2;

    // using inorder traversal , since it is already sorted and in the mean time keep on track the diff between prev val and root val
    void fun(TreeNode *root)
    {
        if (root->left)
        {
            // cout << root->left->val << "  " ;
            fun(root->left);
        }

        if (val >= 0)
        {
            ans = min(ans, abs(root->val - val));
        }
        val = root->val;
        // cout << endl << val << endl;

        if (root->right)
        {
            // cout << root->right->val << "  " ;
            fun(root->right);
        }
    }

    int getMinimumDifference(TreeNode *root)
    {
        fun(root);
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}