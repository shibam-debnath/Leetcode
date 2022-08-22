// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> nextPermutation(int N, vector<int> nums)
{
    int n = nums.size();

    // refer video to understand the intution - https://www.youtube.com/watch?v=LuLCLgMElus

    // STEP 01 ::: storing last-1 increasing no and a no greater than that
    int last_inc_idx = -1, greater_idx = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            last_inc_idx = i;
            break;
        }
    }

    // EDGE CASE ::: When the array is in decreasing order we'll find last_inc_idx so just sort the whole array
    if (last_inc_idx == -1)
    {
        reverse(nums.begin(), nums.end());
        return nums;
    }

    // STEP 02 ::: now find a number just greater than that in the right and swap it with last_inc_index
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > nums[last_inc_idx])
        {
            swap(nums[last_inc_idx], nums[i]);
            break;
        }
    }

    // ! NOTE : Instead of sorting we can reverse the 2nd half to decrease the time complexity from O(nlogn) to O(n)
    reverse(nums.begin() + last_inc_idx + 1, nums.end());

    return nums;
}

int main()
{
    // Main function goes here
    return 0;
}