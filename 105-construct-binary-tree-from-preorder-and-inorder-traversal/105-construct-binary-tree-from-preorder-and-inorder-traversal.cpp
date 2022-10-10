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
        unordered_map<int, int> mp;
        int idx=0;
        TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
        {

            for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
            TreeNode *root = buildTree(preorder, inorder, 0, inorder.size()-1);
            return root;
        }

     TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd){
         
         // base case
         if(inStart>inEnd) return NULL;
         
         TreeNode *root = new TreeNode(preorder[idx]);
         idx++;
         
         // logic 
         int pos = mp[root->val];
         
         root->left = buildTree(preorder, inorder, inStart, pos-1);
         root->right = buildTree(preorder, inorder, pos+1, inEnd);
         
         return root;
         
         
    }
};