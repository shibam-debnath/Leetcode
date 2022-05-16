#include <bits/stdc++.h>
using namespace std;
#define ll long long

// -> Your runtime beats 28.62 % of cpp submissions.
// -> Your memory usage beats 12.44 % of cpp submissions.

int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (auto &x : nums)
    {
        mp[x]++;
        if (mp[x] > 1)
        {
            return x;
            break;
        }
    }
}
// optimized one

// -> Runtime: 124 ms, faster than 80.13% of C++ online submissions for Find the Duplicate Number.
// -> Memory Usage: 61.3 MB, less than 62.05% of C++ online submissions for Find the Duplicate Number.

int findDuplicate(vector<int> &nums)
{
    // constant space

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[nums[i] - 1])
        {
            return nums[i];
            break;
        }
    }

    return 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
