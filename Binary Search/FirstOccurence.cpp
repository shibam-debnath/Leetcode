// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Keep track of the answer in a variable ans. If you encounter that nums[mid]
//  is equal to target, then store that mid in ans as a potential answer but also
//  go left to explore more possibilities. If better answer exists, update the ans variable. After while loop is over, return ans.

int firstOccurence(vector<int> &nums, int target)
{
    int low = 0, high = (int)nums.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            high = mid - 1; // Look for better answer to the left
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