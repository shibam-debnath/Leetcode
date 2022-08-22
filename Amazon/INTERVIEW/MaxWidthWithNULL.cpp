// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    int data;
    Node *left, *right;

    // Constructor
    Node(int item)
    {
        data = item;
        left = right = NULL;
    }
};

int getMaxWidth(Node *root)
{
    if (root == NULL)
        return 0;

        // store pos of nodes in second val
    // left  child = 2*root+1;
    // right child = 2*root+2;

    queue<pair<Node *, int>> q;
    q.emplace(root, 0);

    int mx_width = 0;

    while (!q.empty())
    {

        int left = q.front().second;
        int right = q.back().second;
        int size = q.size();
        mx_width = max(mx_width, right - left + 1);

        while (size--)
        {
            Node *curr = q.front().first;
            int pos = q.front().second;
            q.pop();

            if (curr->left)
                q.emplace(curr->left, 2 * pos + 1);
            if (curr->right)
                q.emplace(curr->left, 2 * pos + 2);
        }
    }

    return mx_width;
}

// Driver Code
int main()
{

    /*
    Constructed binary tree is:
        1
        / \
        2  3
      / \   \
     4 5	 8
            / \
            6 7
    */

    Node *root;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);

    // Function Call
    cout << (getMaxWidth(root));
}
