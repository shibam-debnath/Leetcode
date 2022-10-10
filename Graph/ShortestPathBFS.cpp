// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    unordered_map<int, vector<int>> G;
    for (auto x : edges)
    {
        int a = x.first;
        int b = x.second;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool flag = false;
    vector<bool> vis(n + 1, false); // since we had 1 based indexing so take n+1
    vector<int> res, par(n + 1, -1);

    queue<int> q;
    q.push(s);
    vis[s] = true;
    par[s] = -1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto &ch : G[curr])
        {
            if (!vis[ch])
            {
                vis[ch] = true;
                q.push(ch);
                par[ch] = curr;
            }
            if (ch == t)
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            break;
    }

    // add path to result

    res.push_back(t);
    while (t != s)
    {
        res.push_back(par[t]);
        t = par[t];
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    // Main function goes here
    return 0;
}