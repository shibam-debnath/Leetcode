// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int ans = nums[0];

        int max_till_now = nums[0];
        int min_till_now = nums[0];

        for (int i = 1; i < n; i++)
        {
            // it is possible that with min product we multiply a negative no and the result is maximum

            // normally -> max_till_now = max(nums[i],nums[i]*max_till_now)
            // if no is negative just swap min_till_nw and max_till_now then
            if (nums[i] < 0)
                swap(min_till_now, max_till_now);
            max_till_now = max(max_till_now * nums[i], nums[i]);
            min_till_now = min(min_till_now * nums[i], nums[i]);

            ans = max(ans, max_till_now);
        }

        return ans;
    }
};


//or\


int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    if (nums.size() == 1)
    {
        return nums[0];
    }

    int ans = nums[0];

    int curMax = nums[0];
    int curMin = nums[0];

    for (int i = 1; i < n; i++)
    {
        // it is possible that with min product we multiply a negative no and the result is maximum

        // normally -> max_till_now = max(nums[i],nums[i]*max_till_now)
        // if no is negative just swap min_till_nw and max_till_now then
        int tmp = curMax;
        curMax = max(tmp * nums[i], max(curMin * nums[i], nums[i]));
        curMin = min(tmp * nums[i], min(curMin * nums[i], nums[i]));

        ans = max(ans, curMax);
    }

    return ans;
}


int
main()
{
    // Main function goes here
    return 0;
}