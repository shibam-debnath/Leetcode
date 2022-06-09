// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> G(n);
        for (double i = 0; i < edges.size(); i++)
        {
            G[edges[i][0]].push_back({edges[i][1], succProb[i]});
            G[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<int> vis(n, 0);

        vector<double> dist(n, 0);

        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;

        // prob and pos
        pq.emplace(1, start); // first param is 1 because we'll multiply at every step and store that prob in dist
        dist[start] = 1;

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            double v_dis = node.first;
            int v = node.second;

            if (vis[v])
            {
                continue;
            }

            vis[v] = 1;

            for (auto child : G[v])
            {

                int new_node = child.first;
                double wt = child.second;

                double new_prob = dist[v] * wt;
                if (new_prob > dist[new_node])
                {
                    dist[new_node] = new_prob;
                    pq.emplace(dist[new_node], new_node);
                }
            }
        }

        return dist[end];
    }
};

int main()
{
    // Main function goes here
    return 0;
}