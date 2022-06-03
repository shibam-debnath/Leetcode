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

vector<string> ans;

void helper(TreeNode *root, string s)
{ // copy of s shouls be passed not the original string. (backtracking)
  // if we pass the original s then new char gets added to the previous string ehich
  // gives wrong ans. backtracking doesn't occur in that case
    // base case
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        s += to_string(root->val); // this node should also be included
        ans.push_back(s);
        return;
    }
    // else
    s += to_string(root->val) + "->";

    helper(root->left, s);
    helper(root->right, s);
}

vector<string> binaryTreePaths(TreeNode *root)
{
    string s = "";
    helper(root, s);
    return ans;
}

int main()
{
    // Main function goes here
    return 0;
}