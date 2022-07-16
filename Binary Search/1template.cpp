// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// search for an element or condition which can be
// determined by accessing a single index in the array

//* Template #1  (left <= right) :

// ### Most basic and elementary form of Binary Search
// ### Search Condition can be determined without comparing to the element's 
//     neighbors (or use specific elements around it) 
// ### No post - processing required 
//     because at each step, you are checking to see if the element has been found.
//     If you reach the end, then you know the element is not found

int binarySearch(vector<int> & nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    
    // Seach space ::: left->right
    while (left <= right)
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
            right = mid - 1;
        }
    }

    // End Condition: left > right
    return -1;
}

int main()
{
    // Main function goes here
    return 0;
}