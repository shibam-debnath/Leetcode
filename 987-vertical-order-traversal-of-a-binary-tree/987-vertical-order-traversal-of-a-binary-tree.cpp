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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;

        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size(); 
            map<int,multiset<int>> mp2;
            while(size--){
                TreeNode *curr = q.front().first;
                int level = q.front().second;
                q.pop();
                
                mp2[level].insert(curr->val);
                
                if(curr->left) q.push({curr->left,level-1});
                if(curr->right) q.push({curr->right,level+1});
            }
            
            for(auto &m : mp2){
                int level = m.first;
                for(auto &x : m.second){
                    mp[level].push_back(x);
                }
            }
        }
        
        vector<vector<int>> res;
        for(auto &m : mp){
            res.push_back(m.second);
        }
        return res;
    }
};