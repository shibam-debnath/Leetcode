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
    vector<TreeNode *> bst(int start, int end)
    {
        // to store ans
        vector<TreeNode *> result;
        // if left > right ie there is no possibility of getting any combination
        if (start > end)
        {
            return {NULL};
        }
        // if it is the leaf node i.e. it is the only node
        else if (start == end)
        {
            // create a node with val start/end and insert to vector of tree using {}
            TreeNode *t = new TreeNode(start);
            return {t};
        }

        // else we have to store all combinatins on both sides of i
        for (int i = start; i <= end; i++)
        {
            // left possible subtree combinations of ith node
            vector<TreeNode *> left = bst(start, i - 1);
            // right possible subtree combinations of ith node
            vector<TreeNode *> right = bst(i + 1, end);

            // finally afrer getting all possibilities we add each left and right combination to a vector of tree

            for (auto x : left)
            {
                for (auto y : right)
                {
                    // as we have ith node and all the left and right combinations
                    // we create a TreeNode and keep inserting all the combinations of ith node to result
                    TreeNode *final = new TreeNode(i, x, y);
                    result.push_back(final);
                }
            }
        }

        return result;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> ans = bst(1, n);
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}