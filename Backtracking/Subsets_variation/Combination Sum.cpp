//Shibam Debnath
//July ,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//* Time Complexity :::  O(2^n *n)   -> 2^n subsets(Recursion) and O(n) for insertion
//* Space Complexity ::: O(2^n *n)

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // to store each subsets
        vector<int> subset;

        // to store all subsets
        vector<vector<int>> subsets_all;

        combination_sum(subset, candidates, target, 0, subsets_all);
        return subsets_all;
    }

    void combination_sum(vector<int> &subset, vector<int> &candidates, int t, int index, vector<vector<int>> &subsets_all)
    {

        if (t == 0)
        {
            subsets_all.push_back(subset);
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] > t)
                continue;

            subset.push_back(candidates[i]);
            combination_sum(subset, candidates, t - candidates[i], i, subsets_all); //! since we can take the ith element again so take i instead of i+1
            subset.pop_back();
        }
    }
};

int main() {
    //Main function goes here
    return 0;
}