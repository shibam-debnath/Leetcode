// Shibam Debnath
// May 16,2022

#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    long long mini = a[m - 1] - a[0];
    for (long long i = 1; i < a.size() - m + 1; i++)
    {
        mini = min(mini, a[i + m - 1] - a[i]);
    }
    return mini;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n = 7, m = 3;
    vector<long long> a = {1, 245, 23, 6437353, 335, 436, 57};
    cout << findMinDiff(a, n, m);
    return 0;
}
