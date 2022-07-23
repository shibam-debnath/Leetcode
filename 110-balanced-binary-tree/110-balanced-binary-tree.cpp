
class Solution {
public:
    int height(TreeNode *root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int l_h = height(root->left);
        int r_h = height(root->right);
        
        if(abs(l_h-r_h) <=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};