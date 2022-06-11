// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();

        int t = 0;
        // we first find the target sum we need to find in the subarray to minimise
        // no of operation
        for (auto &i : nums)
        {
            t += i;
        }
        // substract x to get target sum for subarray
        t = t - x;
        if (t < 0)
            return -1;

        // no we will try to find longest subarray with given target
        // sliding window

        int ans = INT_MIN, k = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            while (sum > t)
            {
                sum = sum - nums[k];
                k++;
            }
            if (sum == t)
            {
                ans = max(ans, i - k + 1);
            }
        }
        // finally return max total len - len of max subarray with sum = t
        return ans == INT_MIN ? -1 : n - ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}