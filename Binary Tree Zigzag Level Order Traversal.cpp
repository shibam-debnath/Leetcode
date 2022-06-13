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
    TreeNode() : val(0), left(nullptr), right(nullptr){};
};
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        // using this to flip in alternate levels
        bool dir = false;

        while (!q.empty())
        {
            int size = q.size();
            // cout << size;
            vector<int> vec;
            while (size--)
            {

                auto v = q.front();
                q.pop();
                // cout << v-> val << "  ";
                vec.push_back(v->val);

                if (v->left)
                {
                    q.push(v->left);
                }
                if (v->right)
                {
                    q.push(v->right);
                }
            }
            // changes after each itr
            dir = !dir;
            if (dir)
            {
                ans.push_back(vec);
            }
            else
            {
                reverse(vec.begin(), vec.end());
                ans.push_back(vec);
            }
        }

        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}