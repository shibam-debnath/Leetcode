// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//! Here we just need to remove the duplicates for that
//! STEP 01 : sort nums
//! STEP 02 : use the trick written below

// **TRICK **TO REMOVE DUPLICATES BEFORE INSERTING

//?   if (i != 0 && candidates[i] == candidates[i - 1] && i > index) continue;

//* Time Complexity :::  O(2^n *n)   -> 2^n subsets(Recursion) and O(n) for insertion
//* Space Complexity ::: O(2^n *n)

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        // to store each subsets
        vector<int> subset;

        // to store all subsets
        vector<vector<int>> subsets_all;

        sort(candidates.begin(), candidates.end()); // Sorting is imp to remove dups

        combination_sum(subset, candidates, target, 0, subsets_all);

        return subsets_all;
    }

    void combination_sum(vector<int> &subset, vector<int> &candidates, int t, int index, vector<vector<int>> &subsets_all)
    {

        if (t == 0)
        {
            subsets_all.push_back(subset);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] > t)
                continue;
            if (i != index && candidates[i] == candidates[i - 1])
                continue; //! this trick (IMPORTANT)

            subset.push_back(candidates[i]);
            combination_sum(subset, candidates, t - candidates[i], i + 1, subsets_all);
            subset.pop_back();
        }
    }
};

int main()
{
    // Main function goes here
    return 0;
}