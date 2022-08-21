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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res=INT_MIN;
        int max_path_sum = solve(root,res);
        return res;
    }
    
    int solve(TreeNode *root,int& res){
        if(!root) return 0;
        
        //ignore negative paths
        
        int l =max(0,solve(root->left,res));
        int r =max(0,solve(root->right,res));
        
        res = max(res,root->val + l + r);
        
        return root->val + max(l,r);
    }
};