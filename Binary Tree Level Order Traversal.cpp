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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> dp;

        if (!root)
        {
            return dp;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            // each row shouls be handles once thats why we are calculating size of queue
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = q.front();
                q.pop();
                v.push_back(top->val);
                // insert it's childrens
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            dp.push_back(v);
        }

        return dp;
    }
};

int main()
{
    // Main function goes here
    return 0;
}