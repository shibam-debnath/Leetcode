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
    // int gives runtime error
    // this func gives no of paths possible from that root and stores it in ans variable
    long long possible(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;

        long long ans = 0;
        if (root->val == targetSum)
        {
            ans++;
        }
        // keep on checking untill root == null
        ans += (long long)possible(root->left, (long long)targetSum - root->val);
        ans += (long long)possible(root->right, (long long)targetSum - root->val);
        // finally return no of possibilities
        return ans;
    }

    int pathSum(TreeNode *root, int t)
    {
        if (!root)
            return 0;
        // calculates no of path sum possible for root , root->left and root->right
        return possible(root, t) + pathSum(root->left, t) + pathSum(root->right, t);
    }
};

int main()
{
    // Main function goes here
    return 0;
}