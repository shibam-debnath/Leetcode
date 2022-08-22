// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution
{
private:
public:
    void connect_up(Node *root, unordered_map<Node *, Node *> &mp)
    {
        if (!root)
            return;

        if (root->left)
        {
            mp[root->left] = root;
            connect_up(root->left, mp);
        }
        if (root->right)
        {
            mp[root->right] = root;
            connect_up(root->right, mp);
        }

        return;
    }

    Node *tar(Node *root, int target)
    {
        queue<Node *> q;
        q.push(root);
        Node *ans;
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if (node->data == target)
            {
                ans = node;
                break;
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        return ans;
    }

    Node *get_target(Node *root,int x){

        if(root == NULL) return NULL;
        if(root->data == x) return root;

        Node *left = get_target(root->left,x);
        Node *right = get_target(root->right,x);

        if(left == NULL) return right;
        return left;

    }

    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        unordered_map<Node *, Node *> mp;
        connect_up(root, mp);

        vector<int> res;
        queue<Node *> q;
        Node *t = tar(root, target);
        unordered_map<Node *, bool> vis;
        q.push(t);
        vis[t] = true;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {

                Node *curr = q.front();
                q.pop();

                if (k == 0)
                {
                    res.push_back(curr->data);
                    vis[curr] = true;
                }

                if (curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }

                if (curr->right)
                {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }

                if (mp[curr])
                {
                    q.push(mp[curr]);
                    vis[mp[curr]] = true;
                }
            }
            k--;
            if (k < 0)
                break;
        }

        return res;
    }
};

int main()
{
    // Main function goes here
    return 0;
}