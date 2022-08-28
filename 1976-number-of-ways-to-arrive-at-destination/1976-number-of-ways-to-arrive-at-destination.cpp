class Solution
{
public:
#define ll long long
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<ll, ll>>> G(n);
        for (ll i = 0; i < roads.size(); i++)
        {
            G[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            G[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        return dijkstra(n, G,0);
    }

    int dijkstra(int n, vector<vector<pair<ll, ll>>> G,int src)
    {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n, 0);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

        // cost source
        pq.push({0, src});
        dist[src] = 0;
        ways[src] = 1; // ways to reach source is 1

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            ll curr_dis = node.first;
            ll curr = node.second;
            
            if(curr_dis > dist[curr]) continue;

            for (auto &ch : G[curr])
            {
                ll child = ch.first;
                ll dis = ch.second;

                // update new shortest path if it has smallest path
                ll new_path = dist[curr] + dis;
                if (new_path < dist[child])
                {
                    dist[child] = new_path;
                    ways[child] = ways[curr];
                    pq.push({dist[child], child});
                }
                else if (new_path == dist[child])
                {
                    ways[child] = (ways[child] + ways[curr]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};