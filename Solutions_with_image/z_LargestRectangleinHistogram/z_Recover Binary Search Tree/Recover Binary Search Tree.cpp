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
    TreeNode *diff1 = NULL, *diff2 = NULL;
    TreeNode *pre = new TreeNode(INT_MIN);

    // Approach :

    //   For example array : 1 2 3 4 5 6 7
    //
    //   ->swap random two elments->1 2 6 4 5 3 7(swap 3 and 6)
    //   ->Question is how can know 2 elements is 3 and 6
    //
    //    First : find the first number have index i satisfy arr[i - 1] > arr[i]
    //    = > first mistake have index i - 1 i.e pre

    //    Second : continue but don't  change first mistake, if arr[i - 1] > arr[i] and u had found the
    //    first mistake = > second mistake is i i.e root;
    //    after that just swap the two values as we fount the nodes which were misplaced

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        // left
        inorder(root->left);

        // operation
        if (diff1 == NULL && root->val < pre->val)
        {
            diff1 = pre;
        }

        // imporant : write diff1 != NULL instead of diff2 == NULL because in the 2nd case diff2 is not null actually it was assigned
        // a value when we assigned val to diff1
        if (diff1 == NULL && root->val < pre->val)
        {
            diff2 = root;
        }
        // previous node
        pre = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        // inorder traversal to find the diff elements and finally swap them
        if (!root)
            return;
        inorder(root);
        swap(diff1->val, diff2->val);
    }
};

int main()
{
    // Main function goes here
    return 0;
}