// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//* Time Complexity :::  O(2^n *n)   -> 2^n subsets(Recursion) and O(n) for insertion
//* Space Complexity ::: O(2^n *n)

//! variation of subsets. bas k size wale subset ko rakho


class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        // to store each subsets
        vector<int> subset;

        // to store all subsets
        vector<vector<int>> subsets_all;

        show_subset(subset, 1, n, k, subsets_all);
        return subsets_all;
    }

    void show_subset(vector<int> &subset, int start, int end, int size, vector<vector<int>> &subsets_all)
    {
        // size k walo ko hi accept kro bas
        if (subset.size() == size)
        {
            subsets_all.push_back(subset);
            return;
        }

        for (int i = start; i <= end; i++)
        {
            subset.push_back(i);
            show_subset(subset, i + 1, end, size, subsets_all);
            subset.pop_back();
        }
    }
};

int main()
{
    // Main function goes here
    return 0;
}