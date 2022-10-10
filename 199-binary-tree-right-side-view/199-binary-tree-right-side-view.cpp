class Solution
{
    public:
    vector<int> rightSideView(TreeNode *root)
    {
        if(!root) return{};
        
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int val = q.back()->val;
            cout << val << " ";
            res.push_back(val);
            
            int size = q.size();
            
            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return res;
    }
};