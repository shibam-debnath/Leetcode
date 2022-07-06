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