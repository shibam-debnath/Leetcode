// Shibam Debnath
// May 18,2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int ans;

    unordered_map<int, int> mp;

    mp[nums[0]]++;

    for (int i = 1; i < n; i++)
    {

        if (nums[i] + nums[i - 1] == k)
        {
            mp[nums[i]]++;
        }
        else if (nums[i] + nums[i - 1] < k)
        {
            nums[i] += nums[i - 1];
        }
        else if (nums[i] == k)
        {
            mp[nums[i]]++;
            nums[i] = 0;
        }
    }
    for (auto &x : mp)
    {
        ans += x.second;
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
    }
    return 0;
}
