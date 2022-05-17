// Shibam Debnath
// May 16,2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxProfit(vector<int> &p)
{
    int n = p.size();
    if (n<2){
        return 0;
    }
    int min_no = p[0];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, p[i] - min_no);

        min_no = min(min_no, p[i]);
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
