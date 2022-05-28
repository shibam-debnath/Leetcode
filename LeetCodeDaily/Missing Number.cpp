// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    for (i; i < nums.size(); i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
    return i;
}
int main()
{
    // Main function goes here
    return 0;
}