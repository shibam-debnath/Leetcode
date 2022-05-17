// Shibam Debnath
// May 17,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int calc(TreeNode *original, TreeNode *target)
{

    if (original == target)
    {
        return 0;
    }
    return 1 + (calc(original->left, target) || calc(original->right, target));
}
TreeNode *find(TreeNode *cloned, TreeNode *target, int h)
{
}

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
    int h = calc(original, target);

    TreeNode *ans = find(cloned, target, h);

    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
    }
    return 0;
}
