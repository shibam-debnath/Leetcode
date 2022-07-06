class Solution
{
    public:

       	// Time Complexity :::  O(2^n *n)   -> 2^n subsets(Recursion) and O(n) for insertion
       	// Space Complexity ::: O(2^n *n)

        vector<vector < int>> subsetsWithDup(vector<int> &nums)
        {
           	// to store each subsets
            vector<int> subset;

           	// to store all subsets
            vector<vector < int>> subsets_all;
            
            sort(nums.begin(),nums.end());
            show_subset(subset, nums, 0, subsets_all);
            
            return subsets_all;
        }

    void show_subset(vector<int> &subset, vector<int> &nums, int index, vector< vector< int>> &subsets_all)
    {
        subsets_all.push_back(subset);

        for (int i = index; i < nums.size(); i++)
        {
            if(i!=0 && nums[i]==nums[i-1] && i>index) continue; 
            
            subset.push_back(nums[i]);	//add
            show_subset(subset, nums, i + 1, subsets_all);
            subset.pop_back();	//remove
        }
    }

};