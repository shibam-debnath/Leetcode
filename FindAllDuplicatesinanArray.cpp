// Shibam Debnath
// May 17,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Your runtime beats 74.48 % of cpp submissions
vector<int>
findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
        {
            ans.push_back(abs(nums[i]));
        }
        else
        {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }

    return ans;
}

// Runtime: 117 ms, faster than 27.25% of C++ online submissions for Find All Duplicates in an Array.
// Memory Usage: 44.2 MB, less than 27.80% of C++ online submissions for Find All Duplicates in an Array.

vector<int> findDuplicates(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto &x : nums)
    {
        mp[x]++;
    }
    nums.clear();

    for (auto &it : mp)
    {
        if (it.second == 2)
        {
            nums.push_back(it.first);
        }
    }

    return nums;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
    }
    return 0;
}
