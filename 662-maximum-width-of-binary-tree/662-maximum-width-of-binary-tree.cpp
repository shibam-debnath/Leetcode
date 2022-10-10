/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    #define ll long long
        int widthOfBinaryTree(TreeNode *root)
        {
           	// node and index 
            queue<pair<TreeNode*, ll>> q;
            q.push({ root,0 });

            ll max_w = 0;

            while (!q.empty())
            {

                int size = q.size();
                
                ll start = q.front().second;
                ll last = q.back().second;

                ll width = last - start + 1;
                max_w = max(max_w, width);

                while (size--)
                {
                    TreeNode *v = q.front().first;
                    
                    ll idx = q.front().second;
                    idx-=start; // to remove the overflow
                    
                    q.pop();

                   	// go to child i.e. next level

                    if (v->left)
                    {
                        q.push({ v->left,
                            2 *idx + 1 });
                    }

                    if (v->right)
                    {
                        q.push({ v->right,
                            2*idx + 2 });
                    }
                }
            }

            return max_w;
        }
};