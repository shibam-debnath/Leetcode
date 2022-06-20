// C++ program to find path length
// having maximum number of bends
#include <bits/stdc++.h>
using namespace std;

// structure node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

// Utility function to create a new node
struct Node *newNode(int key)
{
    struct Node *node = new Node();
    node->left = NULL;
    node->right = NULL;
    node->key = key;

    return node;
}

/* Recursive function to calculate the path
length having maximum number of bends.
The following are parameters for this function.

node --> pointer to the current node
dir --> determines whether the current node
is left or right child of it's parent node
bends --> number of bends so far in the
current path.
maxBends --> maximum number of bends in a
path from root to leaf
soFar --> length of the current path so
far traversed
len --> length of the path having maximum
number of bends
*/

int maxBends = 0;
int maxLen = 0;

void helper(struct Node *root, char dir, int bends, int lenSoFar)
{
    // cout << root->key << " ";
    // Base Case
    if (!root)
    {
        return;
    }
    // Leaf node
    if (!root->left && !root->right)
    {
        // leaf node so calculate/ compare bends if t is the smaleest or not
        if (bends > maxBends)
        {
            maxBends = bends;
            maxLen = lenSoFar;
        }
    }

    // Recurring for both left and right child
    if (dir == 'r')
    {
        // prev node dir = r
        if (root->left)
        {
            helper(root->left, 'l', bends + 1, lenSoFar + 1);
        }
        if (root->right)
        {
            helper(root->right, 'r', bends, lenSoFar + 1);
        }
    }
    else
    {
        // prev node dir = l
        if (root->right)
        {
            helper(root->right, 'l', bends + 1, lenSoFar + 1);
        }
        if (root->left)
        {
            helper(root->left, 'r', bends, lenSoFar + 1);
        }
    }
}

// Helper function to call findMaxBendsUtil()
int findMaxBends(struct Node *node)
{
    if (!node)
    {
        return 0;
    }

    int len = 0, bends = 0, max_bend = 0;

    // changing var = bends & len
    // we go to both directions with storing/sending the directions
    if (node->left)
        helper(node->left, 'l', bends, len);
    if (node->right)
        helper(node->right, 'r', bends, len);

    maxLen++; // include root also
    // max length with maximum bends
    return maxLen;
}

// Driver code
int main()
{
    /* Constructed binary tree is
          10
          / \
         8    2
        / \  /
        3  5 2
              \
               1
              /
             9
        */

    struct Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    root->right->left->right = newNode(1);
    root->right->left->right->left = newNode(9);
    root->right->left->left = newNode(4);

    cout << findMaxBends(root);

    return 0;
}
