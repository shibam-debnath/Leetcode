class Solution
{
    public:
    vector<vector < int>> ans;
    vector<vector < int>> permute(vector<int> &nums)
    {
        vector<bool> vis(nums.size());
        vector<int> v;
        permutations(nums,v, vis);
        return ans;
    }

    void permutations(vector<int>& nums,vector<int>& v, vector<bool> &vis)
    {
       	//base case
        if (v.size() >= nums.size())
        {
            ans.push_back(v);
            return;
        }

       	// decision space
        for (int i=0;i<nums.size();i++)
        {
           	// if isValid go there
            if (!vis[i])
            {
                vis[i] = true;
                v.push_back(nums[i]);
                permutations(nums,v, vis);
                vis[i] = false;
                v.pop_back();
            }
        }
    }
};