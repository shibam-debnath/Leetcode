// Shibam Debnath
// May,2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool canJump(vector<int> &nums)
{
    if (arr[0] == 0)
    {
        return false;
    }
    int n = arr.size();
    bool dp[n];
    dp[n - 1] = true;

    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = false;
        // we need to check from that position can we nreach end point
        if ((i + arr[i]) < n && arr[i + arr[i]] == true)
        {
            dp[i] = true;
        }
        else
        {
            for (int j = 1; j <= nums[i] && i + j < n; j++)
            {
                if (dp[i + j])
                {
                    dp[i] = true;
                    break;
                }
            }
            while (i + arr[i]<n>)
            {
                if (dp[i + arr[i]] == true)
                {
                    dp[i] = true;
                    break;
                }
                arr[i]--;
            }
        }
    }

    return dp[0];
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
