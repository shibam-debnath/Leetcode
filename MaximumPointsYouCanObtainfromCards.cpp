// Shibam Debnath
// May 19,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxScore(vector<int> &card, int k)
{
    int n = card.size();
    int lSum = 0;

    for (int i = 0; i < k; ++i)
    {
        lSum += card[i];
    }
    int maxi = lSum;

    for (int rSum = 0, i = 0; i < k; ++i)
    {
        rSum += card[n - 1 - i];
        lSum -= card[k - 1 - i];
        maxi = max(maxi, (lSum + rSum));
    }
    return maxi;
}

int main()
{

    return 0;
}
