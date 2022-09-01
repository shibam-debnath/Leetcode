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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(q.size()){
            
            int size = q.size();
            int mx = INT_MIN;
            
            while(size--){
                auto curr = q.front();
                q.pop();
                
                mx = max(mx,curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            // cout << mx << endl;
            res.push_back(mx);
        }
        return res;
    }
};