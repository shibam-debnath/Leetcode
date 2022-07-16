// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int left = 0, right = n - 1, mid = 0;
        // whenever we find nums[l] < nums[r] then always nums[l] is the min val !try it in copy
        while (left < right)
        {
            mid = left + (right - left) / 2;

            if (nums[left] < nums[right])
            {
                // we found the sorted search space
                return nums[left];
            }

            // if nums[mid] >= nums[left] that means left->mid is in right form so go to right for our ans
            if (nums[mid] >= nums[left])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main()
{
    // Main function goes here
    return 0;
}