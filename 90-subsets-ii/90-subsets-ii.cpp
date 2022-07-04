class Solution
{
    public:

       	// Time Complexity :::  O(2^n *n)   -> 2^n subsets(Recursion) and O(n) for insertion
       	// Space Complexity ::: O(2^n *n)

        vector<vector < int>> subsetsWithDup(vector<int> &nums)
        {
            sort(nums.begin(),nums.end());
           	// to store each subsets
            vector<int> subset;
           	// to store all subsets
            vector<vector < int>> subsets_all;

            show_subset(subset, nums, 0, subsets_all, true);
            return subsets_all;
        }



    void show_subset(vector<int> &subset, vector<int> &nums, int i, vector< vector< int>> &subsets_all, bool prev)
    {

       	// base case
        if (i == nums.size())
        {
            subsets_all.push_back(subset);
            return;
        }
        else
        {
           	// not adding the element
            show_subset(subset, nums, i + 1, subsets_all, false);
           	// if we haven't taken prev element and curr element is same as prev element
           	// we'll be taking this time too
            if (i > 0 && nums[i] == nums[i - 1] && !prev) return;

           	// adding the element
            subset.push_back(nums[i]);
            show_subset(subset, nums, i + 1, subsets_all, true);
            subset.pop_back();
        }
    }
};