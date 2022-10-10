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
    int averageOfSubtree(TreeNode* root) {
        
        if(!root) return 0;
        
        int s= sum(root);
        int c = count(root);
        int res = (s/c==root->val) + averageOfSubtree(root->left) + averageOfSubtree(root->right);
        return res;
            
//         int sum = root->val + averageOfSubtree(root->left) + averageOfSubtree(root->right);
//         cout << endl << sum << " " << root->val <<  endl;
//         int nodes = 1;
        
//         if(root->left) nodes++;
//         if(root->right) nodes++;
        
//         if(root->val == sum/nodes){
//             res++;
//             root->val = sum/nodes;
//             cout << root->val << " ";
//         }
//         else if(root->val != sum/nodes){
//             root->val = sum/nodes;
//             cout << root->val << " ";
//         }
//         return res;
    }
    
    int sum(TreeNode *root){
        if(!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    
    int count(TreeNode *root){
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};