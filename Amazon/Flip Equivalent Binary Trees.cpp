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

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        // base case
        if (!root1 && !root2)
        {
            // both reached the end
            return true;
        }
        else if (!root1 || !root2)
        {
            // kisi ek mein node exist nehi krta  return false
            return false;
        }
        // Logic
        else if (root1->val != root2->val)
        {
            return false;
        }

        // recursive call to (1-l,2-l) && (1-r,2-r)  or swapped version - (1-l,2-r) && (1-r,2-l)

        // dono mese koibhi ek true aaya to return true
        return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
               flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    }
};

int main()
{
    // Main function goes here
    return 0;
}