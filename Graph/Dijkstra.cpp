// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 10;

vector<int> dijkstra(int source, int n, vector<vector<pair<int, int>>> G)
{
    // distance vector initialized with infinity and priority queue
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.emplace(0, source);
    dist[source] = 0;

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        int v_dis = node.first;
        int v = node.second;

        for (auto child : G[v])
        {
            int new_node = child.first;
            int dis = child.second;

            // update new shortest path if it has smallest path
            int new_path = dist[v] + dis;
            if (new_path < dist[new_node])
            {
                dist[new_node] = new_path;
                pq.emplace(dist[new_node], new_node);
            }
        }
    }

    return dist;
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
        return dijkstra(n, G);
    }

    int dijkstra(int n, vector<vector<pair<ll, ll>>> G)
    {
        vector<ll> dist(n, INT_MAX);
        vector<ll> ways(n, 0);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

        // cost source
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1; // ways to reach source is 1

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            ll curr_dis = node.first;
            ll curr = node.second;

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

class Solution
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        int A_start_m = stoi(arriveAlice.substr(0, 2));
        int A_start_d = stoi(arriveAlice.substr(3, 2));
        int A_end_m = stoi(leaveAlice.substr(0, 2));
        int A_end_d = stoi(leaveAlice.substr(3, 2));

        int B_start_m = stoi(arriveBob.substr(0, 2));
        int B_start_d = stoi(arriveBob.substr(3, 2));
        int B_end_m = stoi(leaveBob.substr(0, 2));
        int B_end_d = stoi(leaveBob.substr(3, 2));

        int left_m = 0, left_d = 0, right_m = 0, right_d = 0;

        // left part
        if (A_start_m == B_start_m)
        {
            if (A_start_d >= B_start_d)
            {
                left_m = A_start_m;
                left_d = A_start_d;
            }
            else
            {
                left_m = B_start_m;
                left_d = B_start_d;
            }
        }
        else if (A_start_m > B_start_m)
        {
            left_m = A_start_m;
            left_d = A_start_d;
        }
        else
        {
            left_m = B_start_m;
            left_d = B_start_d;
        }

        // right part
        if (A_end_m == B_end_m)
        {
            if (A_end_d <= B_end_d)
            {
                right_m = A_end_m;
                right_d = A_end_d;
            }
            else
            {
                right_m = B_end_m;
                right_d = B_end_d;
            }
        }
        else if (A_start_m < B_start_m)
        {
            right_m = A_end_m;
            right_d = A_end_d;
        }
        else
        {
            right_m = B_end_m;
            right_d = B_end_d;
        }

        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // calc days
        long long res = 0;
        int i = left_m;
        while (i != right_m)
        {
            if (i == left_m)
            {
                res += days[left_m - 1] - left_d;
            }
            else
            {
                res += days[left_m - 1];
            }
        }
        // add last month
        res += right_d;

        return res;
    }
};