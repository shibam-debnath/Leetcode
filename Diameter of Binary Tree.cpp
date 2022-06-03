// Shibam Debnath
// June 02,2022

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#define ll long long
class Solution
{
public:
    int ans = 0;
    int helper(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        // calculate the longest path in both left child and right child
        int left = helper(root->left);
        int right = helper(root->right);

        // last step - store the max diameter val in ans(we only store the max val here)
        ans = max(ans, left + right);

        return 1 + max(left, right); // returns the longest one between left_path and right_path;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        helper(root);
        return ans;
    }
};
int main()
{
    // Main function goes here
    return 0;
}