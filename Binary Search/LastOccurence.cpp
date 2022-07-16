// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lastOccurence(vector<int> &nums, int target)
{
    int ans = -1;
    int low = 0, high = (int)nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1; // Go right for better answers
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    // Main function goes here
    return 0;
}