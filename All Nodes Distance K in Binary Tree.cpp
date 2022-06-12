// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> G;

    // this functions makes connection in upwars direction
    void connect(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        // go to left nide and make connection with parent
        if (root->left)
        {
            G[root->left] = root;
            connect(root->left);
        }
        // go to right nide and make connection with parent
        if (root->right)
        {
            G[root->right] = root;
            connect(root->right);
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // first make backward relations with parents
        // since we have to traverse upwars also
        connect(root);
        // now bfs laga do from target node and whenever you reach kth node insert to vector
        vector<int> ans;
        // visited array
        unordered_map<TreeNode *, bool> vis;
        // queue for bfs
        queue<TreeNode *> q;
        q.push(target);
        vis[target] = true;

        while (!q.empty())
        {
            int size = q.size();
            // use this methos whenever we want to calc min width or distance
            while (size--)
            {
                // acces data
                TreeNode *node = q.front();
                q.pop();

                // conditions
                if (k == 0)
                {
                    ans.push_back(node->val);
                    // make visited
                    vis[node] = true;
                }

                // go to all possible childs/even parents this time and check
                if (node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                // right side
                if (node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                // parents
                //  if node has parent node and it is not visited then insert to q
                if (G[node] && !vis[G[node]])
                {
                    q.push(G[node]);
                    vis[G[node]] = true;
                }
            }
            k--;

            if (k < 0)
                break; // we don't need to check anymore
        }
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}