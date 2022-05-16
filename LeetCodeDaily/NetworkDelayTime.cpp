#include <bits/stdc++.h>
using namespace std;
#define ll long long
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    // adjasensy matrix
    vector<vector<pair<int, int>>> dp(n + 1);
    // push elements
    for (int i = 0; i < times.size(); i++)
    {
        dp[times[i][0]].push_back({times[i][1], times[i][2]});
    }
    // priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // dist vector
    int dist[n + 1];
    // initializing with infinity
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    int ans = 0;

    // q pe 0 push krte hein , k==start pos
    q.push({0, k});

    dist[0] = 0;

    while (!q.empty())
    {
        // q.second = position(start)
        int x = q.top().second;
        q.pop();

        // traverse its adjascent nodes
        //   it.second = weight
        //   it.first = position
        //  dist[it.first] = weight upto that position

        for (auto &it : dp[x])
        {
            if (it.second + dist[it.first] < dist[it.first])
            {
                dist[it.first] = it.second + dist[it.first];
                q.push({dist[it.first], it.first});
            }
        }

        for (int i = 0; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
            {
                return 1;
            }
            ans = max(ans, dist[i]);
        }
    }

    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
    }
    return 0;
}
