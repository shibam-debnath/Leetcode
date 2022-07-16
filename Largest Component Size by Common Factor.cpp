// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> parent;
    vector<int> sizes;

    void make(int i)
    {
        parent[i] = i;
        sizes[i] = 1;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int i, int j)
    {
        // find their parents first
        i = find(i);
        j = find(j);

        if (i == j)
            return;
        else
        {
            if (sizes[i] < sizes[j])
                swap(i, j);
            // since i==largest, So it is the root
            parent[j] = i;
            // increase sizes of root
            sizes[i] += sizes[j];
        }
        parent[j] = i;
    }

    int largestComponentSize(vector<int> &nums)
    {
        int nodes = *max_element(nums.begin(), nums.end());

        parent.resize(nodes + 1);
        sizes.resize(nodes + 1);

        for (int i = 0; i < nodes + 1; ++i)
        {
            make(i);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 2; j <= sqrt(nums[i]); ++j)
            {
                if (nums[i] % j == 0)
                {
                    Union(nums[i], j);
                    Union(nums[i] / j, j);
                }
            }
        }

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            int _x = find(nums[i]);
            map[_x]++;
        }

        int mx = 0;
        for (auto &m : map)
            mx = max(mx, m.second);

        return mx;
    }
};

int main()
{
    // Main function goes here
    return 0;
}