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

//          0          0 <- idx
//        /   \
//       1     2                 (Here 1 is obtained = 2*idx+1 && 2 is obtained = 2*idx+2)
//     /  \   /  \     1 <- idx  for 1 but idex-> 2 for 2
//    3  NULL 5   6              (Here 3 is obtained = 2*idx(1)+1 && 5 is obtained = 2*idx(2)+2)

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, ll>> q;
        // int idx=0;
        q.push({root, 0});

        ll ans = 0;
        while (!q.empty())
        {
            ll front = q.front().second;
            ll back = q.back().second;

            // in each level calculate the width which is the diif betwenn first and last val and check if it is the max width or not n
            ans = max(ans, back - front + 1);

            ll size = q.size();
            // cout << size;
            while (size--)
            {
                auto v = q.front();
                TreeNode *node = v.first;
                // if we find index using prev level node val then it gives runtime error after a large level since it is multiplied by 2 everytime. So we need to optimize it.
                // what we do is that since we are calculating the diff only so we substrack the idx by a val everytime
                // eg - 8-4 = 4
                //    (8-2)-(4-2) = 4
                ll idx = v.second - front;
                // we can also use unsigned long long int no to get runtime error 
                q.pop();

                if (node->left)
                {
                    q.push({node->left, 2 * idx + 1});
                }
                if (node->right)
                {
                    q.push({node->right, 2 * idx + 2});
                }
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