// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int camera = 0;
    int need_cam=1;
    int not_req =-1;

    int dfs(TreeNode *root){
        if (!root)
        {
            return not_req;
        }
        // go to left and right childs
        int left = dfs(root->left);
        int right = dfs(root->right);

        if((left == need_cam) || right == need_cam){
            camera++;
            return not_req;
        }

        
        if(left == not_req || right == not_req){
            return 0;
        }
        else{
            return need_cam;
        }
    } 
    
    int minCameraCover(TreeNode *root)
    {
        

        if(dfs(root)==need_cam){
            camera++;
        }
        return camera;
    }
};

int main()
{
    // Main function goes here
    return 0;
}