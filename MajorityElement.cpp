// Shibam Debnath
// May 19,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int majorityElement(vector<int> &nums)
{
    int n = nums.size() / 2;
    unordered_map<int, int> mp;

    for (auto &x : nums)
    {
        mp[x]++;
        if (mp[x] > n)
        {
            return x;
        }
    }
    return 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    return 0;
}
