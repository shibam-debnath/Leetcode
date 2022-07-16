// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//* Time Complexity :::  O(2^n *n)   -> 2^n subsets(Recursion) and O(n) for insertion
//* Space Complexity ::: O(2^n *n)

class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> vis(nums.size());
        vector<int> v;
        permutations(nums, v, vis);
        return ans;
    }

    void permutations(vector<int> &nums, vector<int> &v, vector<bool> &vis)
    {
        // base case
        if (v.size() >= nums.size())
        {
            ans.push_back(v);
            return;
        }

        // decision space
        for (int i = 0; i < nums.size(); i++)
        {
            // if isValid i.e not visited go there
            if (!vis[i])
            {
                // add value
                vis[i] = true;
                v.push_back(nums[i]);

                // recurse to remaining
                permutations(nums, v, vis);

                // remove value
                vis[i] = false;
                v.pop_back();
            }
        }
    }
};

int main()
{
    // Main function goes here
    return 0;
}
