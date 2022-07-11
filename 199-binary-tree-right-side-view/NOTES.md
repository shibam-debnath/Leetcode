​
class Solution
{
public:
​
vector<int> v;
void dfs(TreeNode *root, int height)
{
if (!root)
{
return;
}
if (v.size() == height)
{
v.push_back(root->val);
}
​
dfs(root->right, height + 1);
dfs(root->left, height + 1);
}
vector<int> rightSideView(TreeNode *root)
{
​
dfs(root, 0);
return v;
}
};