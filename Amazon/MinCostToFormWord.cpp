#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;
vector<int> v;
int ans = INT_MAX;
void solve(int x, string &s, int n, int cost)
{
    if (x == n)
    {
        ans = min(ans, cost);
        return;
    }
    string t;

    for (int i = x; i < n; i++)
    {

        t += s[i];
        cout << t << " " << i << "  ";
        if (m.find(t) != m.end())
        {
            solve(i + 1, s, n, cost + m[t]);
        }
    }
    cout << endl;
    return;
}
int main()
{
    string s = "location";
    int n = s.length();
    m.insert({"lo", 4});
    m.insert({"ca", 5});
    m.insert({"loca", 13});
    m.insert({"tion", 10});
    m.insert({"ti", 5});
    m.insert({"on", 1});
    solve(0, s, n, 0);
    cout << ans;

    return 0;
}