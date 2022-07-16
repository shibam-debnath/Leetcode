// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        // LIS variation
        int n = nums.size();

        int up = 1, down = 1;
        for (int i = 1; i < n; i++)
        {

            if (nums[i - 1] < nums[i])
            {
                // calculate no of prev ans + new curr up
                up = down + 1;
            }
            else if (nums[i - 1] > nums[i])
            {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};

int main()
{
    // Main function goes here
    return 0;
}