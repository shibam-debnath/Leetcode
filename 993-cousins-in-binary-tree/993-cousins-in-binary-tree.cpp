/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        
    int par1, par2, depth1, depth2;

    void dfs(TreeNode *root, int x, int y, int par, int depth)
    {
        if(!root) return;
        
        if(root->val == x){
            par1 = par;
            depth1 = depth;
            return;
        }
        
        if(root->val == y){
            par2 = par;
            depth2 = depth;
            return;
        }
        
        dfs(root->left,x,y,root->val,depth+1);
        dfs(root->right,x,y,root->val,depth+1);
    }

    bool isCousins(TreeNode *root, int x, int y)
    {

        if (root->val == x || root->val == y) return false;
        dfs(root, x, y, 0, 0);

        if (par1 != par2 && depth1 == depth2) return true;
        return false;
    }
};