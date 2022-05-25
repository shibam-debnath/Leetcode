//Shibam Debnath
//May 23,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//gives tle for 10^5 
int maxEnvelopes(vector<vector<int>> &e)
{
    sort(e.begin(), e.end());
    int n = e.size();
    int dp[n + 1];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int max = 0;

        for (int j = 0; j < i; j++)
        {
            if (e[j][1] < e[i][1] && e[j][0] < e[i][0])
            {
                if (dp[j] > max)
                {
                    max = dp[j];
                }
            }
        }

        dp[i] = max + 1; // storing the no of max envelopes

        // store max val
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }

    return ans;
}
int main() {
    //Main function goes here
    return 0;
}