// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> ans;

vector<int> leftView(Node *root)
{
    if (!root)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        ans.push_back(q.front()->data);
        while (size--)
        {
            auto it = q.front();
            q.pop();

            if (it->left)
            {
                q.push(it->left);
            }
            if (it->right)
            {
                q.push(it->right);
            }
        }
    }

    return ans;
}

vector<int> ans;
void bfs(Node *root)
{
    if (!root)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        int n = q.size();
        int v = q.front()->data;
        ans.push_back(v);
        while (n--)
        {
            Node *temp = q.front();
            q.pop();

            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);

            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

vector<int> leftView(Node *root)
{
    bfs(root);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->right = new Node(4);
    root->right->left = new Node(3);
    root->right->left->left = new Node(5);
    root->right->right = new Node(4);
    root->right->right->left = new Node(7);

    vector<int> vec = leftView(root);
    for (int x : vec)
        cout << x << " ";
    cout << endl;

    return 0;
}