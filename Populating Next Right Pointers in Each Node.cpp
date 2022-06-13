// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return root;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            Node *last = NULL;
            while (size--)
            {
                auto curr = q.front();
                q.pop();
                // operation
                // first we set of next of last node to null then keep doing the same for rest untill first in level order
                // prev_>next = current
                curr->next = last;
                // curr = prev
                last = curr;
                //  child visit

                // imp : visit right first since we are starting from right
                if (curr->right)
                {
                    cout << curr->right->val << "  ";
                    q.push(curr->right);
                }
                if (curr->left)
                {
                    cout << curr->left->val << "  ";
                    q.push(curr->left);
                }
            }
        }
        return root;
    }
};

int main()
{
    // Main function goes here
    return 0;
}