#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Runtime: 10 ms, faster than 9.04% of C++ online submissions for Sort Colors.
// Memory Usage: 8.4 MB, less than 25.33% of C++ online submissions for Sort Colors.

// int sort(vector<int> &nums, int k)
// {
//     unordered_map<int, int> mp;

//     for (auto &x : nums)
//     {
//         mp[x]++;
//     }

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i < mp[0])
//         {
//             nums[i] = 0;
//         }
//         if (i < mp[0] + mp[1] && i >= mp[0])
//         {
//             nums[i] = 1;
//         }
//         if (i < mp[0] + mp[1] + mp[2] && i >= mp[0] + mp[1])
//         {
//             nums[i] = 2;
//         }
//     }
// }

// three ponter

// Your runtime beats 68.30 % of cpp submissions
// Your memory usage beats 75.04 % of cpp submissions.

int removeDuplicates(vector<int> &nums)
{
    int i = 0, j = 1, temp;
    if (nums.size() == 1 || nums.size() == 0)
    {
        return nums.size();
    }
    while (j < nums.size())
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
        j++;
    }

    return i + 1;
}

int main()
{

    vector<int> nums = {2, 0, 1};
    sortColors(nums);

    for (auto &x : nums)
    {
        cout << x << " ";
    }

    return 0;
}
