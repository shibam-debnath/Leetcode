// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// TWO CONCEPTS

// CASE 01 ::: if prefix(0,x) == prefix(0,y)
//             = > sum of subarray from(x + 1) to(y) is zero.arr[x + 1, y] = 0 int maxLen(vector<int> nums, int n)

// CASE 02 ::: Now if at any point prefix_sum==0 , ie subarry from (0) to (y) is zero

int maxLen(int arr[], int n)
{
    int pre_sum = 0, max_len = INT_MIN, len = 0;
    // prefix sum and their position
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];

        if (pre_sum == 0)
        {
            max_len = max(max_len, i + 1);
        }

        if (mp.find(pre_sum) != mp.end())
        {
            // map mein already h
            max_len = max(max_len, i - mp[pre_sum]);
        }
        // current len
        mp[pre_sum] = i;
    }

    return max_len;
}

int main()
{
    // Main function goes here

    int n = 6;
    int arr[] = {2, -2, 2, 5, 7, -12};
    cout << maxLen(arr, n);
    return 0;
}