// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Search Condition needs to access the element's immediate right neighbor

//! Template #2  (left < right) : FIRST OCCURANCE PROBLEMS

// ### Search Condition needs to access the element's immediate right neighbor
// ### Use the element's right neighbor to determine if the condition is met
//     and decide whether to go left or right
// ### Guarantees Search Space is at least 2 in size at each step
// ### Post-processing required. Loop/Recursion ends when you have 1 element left. 
//     Need to assess if the remaining element meets the condition.

int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size();
    while (left < right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left == right
    if (left != nums.size() && nums[left] == target)
        return left;
    return -1;
}

int main()
{
    // Main function goes here
    return 0;
}