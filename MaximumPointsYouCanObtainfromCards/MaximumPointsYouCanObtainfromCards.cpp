// Shibam Debnath
// May 17,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// All you need to know is about "prefix sum" topic. since "prefix sum" is very useful to solve this
// kind fo subarray problem.
// Whenever you see some problem related to subarray and about sum. Think about prefixSum first.

int maxScore(vector<int> &card, int k)
{
    int n = card.size();
    int sum = 0;
    // check the diagram for reference
    // we are using sliding window on rest of the part and finding it's min sum

    int max_sum = 0;

    vector<int> l_sum(n + 1), r_sum(n + 1);
    // cumulative sum from left side
    for (int i = 0; i < k; i++)
    {
        sum += card[i];
        l_sum[i] = sum;
    }
    // cumulative sum of reverse way
    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += card[i];
        r_sum[i] = sum;
    }
    for (int i = 0; i <= k; i++)
    {
        max_sum += max(max_sum, l_sum[k - 1 - i] + r_sum[i]);
    }

    return max_sum;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {

        solve();
    }
    return 0;
}
