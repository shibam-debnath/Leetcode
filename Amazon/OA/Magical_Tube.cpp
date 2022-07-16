// Shibam Debnath
// June,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll query_count;
    cin >> query_count;

    vector<pair<int, int>> v_pair;
    for (int i = 0; i < query_count; i++)
    {
        ll q1, q2;
        cin >> q1 >> q2;
        v_pair.push_back({q1, q2});
    }

    priority_queue<pair<ll, ll>> pq;
    map<ll, ll> mapp;

    ll index = 0;

    vector<ll> v;

    for (int i = 0; i < query_count; i++)
    {
        if (v_pair[i].first == 1)
        {
            ll a = v_pair[i].second;
            mapp[a]++;
            pq.push({mapp[a], index});
        }

        if (v_pair[i].first == 2 && pq.size() != 0)
        {
            auto ele = pq.top();

            ll sec = v_pair[ele.second].second;
            v.push_back(sec);
            mapp[sec]--;
            pq.pop();
        }
        index++;
    }

    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}