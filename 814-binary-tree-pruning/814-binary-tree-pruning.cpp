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
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
        
        // after deleting nodes from bottom check if root can be removed or not
        if(isLeaf(root) and root->val==0) return NULL;
        
        return root;
    }
    
    void helper(TreeNode *root){
        
        if(!root) return;
        
        // start from bottom 
        helper(root->left);
        helper(root->right);
        
        // if node is leaf and has val == 0 then remove it
        if(root->left and isLeaf(root->left) and root->left->val == 0){
            root->left = NULL;
        }
        
        if(root->right and isLeaf(root->right) and root->right->val == 0){
            root->right = NULL;
        }
        
    }
    
    bool isLeaf(TreeNode *root){
        if(!root->left and !root->right) return true;
        return false;
    }
};