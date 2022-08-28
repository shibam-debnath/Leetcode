class Solution
{
    public:
        const int INF = 1e9 + 10;
        int dijkstra(int source, int n, vector<vector<pair<int, int>>> G)
        {
            vector<int> dist(n+1, INF);
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;

            pq.emplace(0, source);
            dist[source] = 0;

            while (!pq.empty())
            {
                auto node = pq.top();
                pq.pop();

                int v_dis = node.first;
                int v = node.second;

                for (auto child: G[v])
                {
                    int new_node = child.first;
                    int wt = child.second;

                    int new_path = dist[v] + wt;
                    if (new_path < dist[new_node])
                    {
                        dist[new_node] = new_path;
                        pq.emplace(dist[new_node], new_node);
                    }
                }
            }
            int ans = 0;
            for(int i=1;i<dist.size();i++){
                ans = max(ans, dist[i]);
            }
            if(ans==INF) return -1;
            return ans;
        }

    int networkDelayTime(vector<vector < int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> dp(n + 1);
        for (int i = 0; i < times.size(); i++)
        {
            dp[times[i][0]].push_back({times[i][1],times[i][2] });
        }
        return dijkstra(k, n, dp);
    }
};