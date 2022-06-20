// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 10;

void dijkstra(int source, int n, vector<vector<pair<int, int>>> G)
{
    // visited vector
    vector<int> vis(n + 1, 0);
    // distance vector initialized with infinity
    vector<int> dist(n + 1, INF);
    // priority queue to store  distance and node (min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // insert source
    pq.emplace(0, source);
    dist[source] = 0;

    // while loop starts
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        // access data from pq.top();
        int v_dis = node.first;
        int v = node.second;

        // check if already visited or not
        // we are doing it here not inside the for loop because a node can be revisited if it has shortest path
        if (vis[v])
        {
            continue;
        }
        vis[v] = 1;

        // go to childrens OF NODE of graph G
        for (auto child : G[v])
        {
            // g ka first is and second is weight
            int new_node = child.first;
            int wt = child.second;

            // update new shortest path if it has smallest path
            int new_path = dist[v] + wt;
            if (new_path < dist[new_node])
            {
                dist[new_node] = new_path;
                pq.emplace(dist[new_node], new_node);
            }
        }
    }
}

int main()
{
    // n - edges , m = vertices
    int n, m;
    cin >> n >> m;
    // graph
    vector<vector<pair<int, int>>> G;

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;

        G[x].push_back({y, wt});
        // if bidirected then
        // G[y].push_back({x, wt});
    }

    // Main function goes here
    return 0;
}
