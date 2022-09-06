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
    int res=0;
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return res;
    }
    
    void helper(TreeNode *root,int mn,int mx){
        if(!root) return;
        
        mn=min(mn,root->val);
        mx=max(mx,root->val);

        if(!root->left and !root->right){
            int difference = mx-mn;
            res=max(res,difference);
            return;
        }
    
        helper(root->left,mn,mx);
        helper(root->right,mn,mx);

    }
};