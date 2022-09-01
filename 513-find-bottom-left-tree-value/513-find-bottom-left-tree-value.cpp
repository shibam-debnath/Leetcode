/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res=root->val;
        int m_depth = 0;
        dfs(root,res,m_depth,0);
        return res;
    }
    void dfs(TreeNode *root,int &res,int &max_d,int depth){
        if(!root) return;
        
        dfs(root->left,res,max_d,depth+1);
        dfs(root->right,res,max_d,depth+1);
        
        if(depth>max_d){
            max_d = depth;
            res=root->val;
        }
    }
};