// Shibam Debnath
// May,2022

// Shibam Debnath
// May,2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x)
    {
        this->val = x;
        left = right = NULL;
    };
};
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    int ans = 0;
    int sum(TreeNode *root, int h)
    {

        if (!root)
        {
            return 0;
        }

        if (h == 1)
        {
            return ans += root->val;
        }

        sum(root->left, h - 1);
        sum(root->right, h - 1);

        return ans;
    }
    int deepestLeavesSum(TreeNode *root)
    {
        int h = height(root);
        int ans = sum(root, h);

        return ans;
    }
};
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    return 0;
}
