class Solution
{
    public:

        vector<vector < int>> subsets(vector<int> &nums)
        {

           	//to store each subsets
            vector<int> subset;

           	//to store all subsets
            vector<vector < int>> subsets_all;

            show_subset(subset, nums, 0, subsets_all);
            return subsets_all;
        }

    void show_subset(vector<int> &subset, vector<int> &nums, int index, vector< vector< int>> &subsets_all)
    {
        subsets_all.push_back(subset);
        for (int i = index; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            show_subset(subset, nums, i + 1, subsets_all);
            subset.pop_back();
        }
    }
};