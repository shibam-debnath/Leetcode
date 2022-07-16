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
    vector<vector<int>> subsets(vector<int> &nums)
    {

        // to store each subsets
        vector<int> subset;

        // to store all subsets
        vector<vector<int>> subsets_all;

        show_subset(subset, nums, 0, subsets_all);
        return subsets_all;
    }

    void show_subset(vector<int> &subset, vector<int> &nums, int index, vector<vector<int>> &subsets_all)
    {
        subsets_all.push_back(subset);

        for (int i = index; i < nums.size(); i++)
        {
            subset.push_back(nums[i]); //add
            show_subset(subset, nums, i + 1, subsets_all);
            subset.pop_back(); //remove
        }
    }
};


// SOLUTION 02


class Solution
{
public:
    void show_subset(vector<int> &subset, vector<int> &nums, int i, vector<vector<int>> &subsets_all)
    {

        // base case
        if (i >= nums.size())
        {
            subsets_all.push_back(subset);
            return;
        }

        // decision space : either take or don't take current 

        // adding the element
        subset.push_back(nums[i]);
        show_subset(subset, nums, i + 1, subsets_all);
        subset.pop_back();

        // not adding the element 
        show_subset(subset, nums, i + 1, subsets_all);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        // to store each subsets
        vector<int> subset;

        // to store all subsets
        vector<vector<int>> subsets_all;

        show_subset(subset, nums, 0, subsets_all);

        return subsets_all;
    }
};

int main()
{
    // Main function goes here
    return 0;
}