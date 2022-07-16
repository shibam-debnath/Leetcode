//Shibam Debnath
//June ,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        // to handle edge cases we are starting from 1 to n-2 since mid+1 & mid-1 may cause errors
        int left = 1, right = n - 2;
        while (left <= right)
        {
            int mid = right + (left - right) / 2;
            // peek condition
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid + 1] > nums[mid])
                left = mid + 1; // go right agar right wala bada dikhe to
            else if (nums[mid - 1] >= nums[mid])
                right = mid - 1; // go left agar left wala bada dikhe
        }
        // handle edge cases
        if (nums[0] > nums[1])
            return 0;
        else if (nums[n - 1] > nums[n - 2])
            return n - 1;
        return -1;
    }
};

int main() {
    //Main function goes here
    return 0;
}