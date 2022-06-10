// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int source, int dst, int k)
    {
        vector<vector<pair<int, int>>> G(n);
        for (int i = 0; i < flights.size(); i++)
        {
            G[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;


        pq.push({0, source, 0});

        vector<int> dist(n, INT_MAX);


        while (!pq.empty())
        {
            auto node = pq.top();

            int cost = node[0];
            int v = node[1];
            int stops = node[2];
            pq.pop();
            if (v == dst)
                return cost;
                
            if (stops > k)
                continue;
            // Optimization: if we already visit this v and it has fewer stops in
            // dist array than in pq we don't need to explore it again.
            if (dist[v] != INT_MAX && dist[v] < stops)
                continue;
            dist[v] = stops;
            for (auto &x : G[v])
            {
                int price = x.second;
                int next = x.first;
                pq.push({cost + price, next, stops + 1});
            }
        }

        return -1;
    }
};

int main()
{
    // Main function goes here
    return 0;
}