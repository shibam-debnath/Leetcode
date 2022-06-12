// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        int end = 0, start = 0, sum = 0, max_v = INT_MIN;
        while (end < n)
        {
            if (mp[nums[end]])
            {
                // already exist;
                while (mp[nums[end]])
                {
                    mp[nums[start]]--;
                    sum -= nums[start];
                    start++;
                }
            }
            else
            {
                sum += nums[end];
                mp[nums[end]]++;
                max_v = max(max_v, sum);
                end++;
            }
        }
        return max_v;
    }
};

int main()
{
    // Main function goes here
    return 0;
}