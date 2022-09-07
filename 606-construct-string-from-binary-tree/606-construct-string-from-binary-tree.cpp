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
        

//     void dfs(TreeNode *root,string &s)
//     {

//         if (!root) return;

//         s+=to_string(root->val);

//         if (root->left)
//         {
//             s.push_back('(');
//             dfs(root->left,s);
//             s.push_back(')');
//         }
//         if (root->right)
//         {
//            	//if root left doesn't exist then only we need to insert this else don't
            
//             if (!root->left)  s = s + "()";
            
//             s.push_back('(');
//             dfs(root->right,s);
//             s.push_back(')');
//         }
//     }

    string tree2str(TreeNode *root)
    {
        if (!root) return "";
        
        string s = to_string(root->val);
        
        if (root->left)
        {
            s += "("+ tree2str(root->left) + ")";
        }
        if (root->right)
        {
            if(!root->left) s+="()";
            s += "("+ tree2str(root->right) + ")";
        }
        
        return s;
    }
};