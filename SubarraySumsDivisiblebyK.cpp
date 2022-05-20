// Shibam Debnath
// May 19,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();

    int mod = 0;
    vector<int> mp(k);
    mp[0] = 1;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        mod = (((nums[i] + mod) % k) + k) % k;
        ans = ans + mp[mod]++;
    }

    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    return 0;
}
