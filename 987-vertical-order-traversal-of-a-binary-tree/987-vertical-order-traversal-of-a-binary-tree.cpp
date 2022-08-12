/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> verticalTraversal(TreeNode *root)
        {
            vector<vector < int>> res;
            map<int, vector < int>> mp;
            queue<pair<TreeNode*, int>> q;
            q.push({ root,
                0 });

            int dis = 0;
            while (!q.empty())
            {
                multiset<pair<int,int>> mmp;
                int size = q.size();
                while (size--)
                {
                    TreeNode *node = q.front().first;
                    dis = q.front().second;
                    q.pop();
                    
                    mmp.insert({dis,node->val});

                    if (node->left) q.emplace(node->left, dis - 1);
                    if (node->right) q.emplace(node->right, dis + 1);
                }
                
                for(auto x : mmp){
                    mp[x.first].push_back(x.second);
                }
            }

            vector<int> v;
            for (auto m: mp)
            {
                v.clear();
                v = m.second;
                res.push_back(v);
            }

            return res;
        }
};