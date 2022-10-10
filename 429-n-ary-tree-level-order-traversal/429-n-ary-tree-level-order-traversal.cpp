/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        vector<int> level;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                // we will print layerwise 
                Node *node = q.front();
                q.pop();
                
                level.push_back(node->val);
                
                for(auto &ch : node->children){
                    q.push(ch);
                }
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};