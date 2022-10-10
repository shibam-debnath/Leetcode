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
    int sumNumbers(TreeNode* root) {
        vector<string> res;
        dfs(root,"",res);
        int ans =0;
        for(auto &s : res){
            ans+=stoi(s);
        }
        return ans;
    }
    
    void dfs(TreeNode *root,string s,vector<string>&str){
        if(!root) return;
        if(!root->left and !root->right){
            s.push_back(root->val+'0');
            str.push_back(s);
            return;
        } 
        s.push_back(root->val+'0');
        dfs(root->left,s,str);
        dfs(root->right,s,str);
    }
};