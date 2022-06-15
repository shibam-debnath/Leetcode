// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Write on pen paper you'll get the approach
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        vector<int> dp(n);
        int p2 = 0, p3 = 0, p5 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] = min(2 * dp[p2], min(3 * dp[p3], 5 * dp[p5]));
            // now we need to increase the required pointer
            if (dp[i] == 2 * dp[p2])
            {
                p2++;
            }
            if (dp[i] == 3 * dp[p3])
            {
                p3++;
            }
            if (dp[i] == 5 * dp[p5])
            {
                p5++;
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    // Main function goes here
    return 0;
}