// Shibam Debnath
// June,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s;
    cin >> s;

    ll n = s.size();
    sort(s.begin(), s.end());

    ll num1 = 0, num2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            num1 = num1 * 10 + (s[i] - '0');
        }
        else
        {
            num2 = num2 * 10 + (s[i] - '0');
        }
    }

    ll ans = num1 + num2;

    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}