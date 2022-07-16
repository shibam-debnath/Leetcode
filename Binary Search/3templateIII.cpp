// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// used to search for an element or condition which requires accessing the
// current index and its immediate left and right neighbor's index in the array

// Search Condition needs to access element's immediate left and right neighbors

int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left + 1 < right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if (nums[left] == target)
        return left;
    if (nums[right] == target)
        return right;
    return -1;
}

int main()
{
    // Main function goes here
    return 0;
}