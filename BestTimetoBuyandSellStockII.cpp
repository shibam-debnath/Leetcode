// Shibam Debnath
// May,2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxProfit(vector<int> &prices)
{
    int profit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    return 0;
}
