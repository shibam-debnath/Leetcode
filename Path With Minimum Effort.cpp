// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<pair<int, int>> dir = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };

    int dijkstra(vector<vector<int>> &h)
    {
        int n = h.size();
        int m = h[0].size();

        vector<vector<pair<int, int>>> G(n);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // insert source indexes and max height diff
        pq.push({0, 0, 0});

        // we need a amtrix to store distance val , matrix because here no node is given indexes are given
        vector<vector<int>> min_h(n, vector<int>(m, INT_MAX));

        // while loop starts
        while (!pq.empty())
        {
            auto node = pq.top();

            int i = node[0];
            int j = node[1];
            int height = node[2];

            pq.pop();

            // check if des obtained
            if (i == n - 1 && j == m - 1)
                return height;

            // check all 4 dir
            for (auto di : dir)
            {
                int new_i = i + di.first;
                int new_j = j + di.second;

                if(new_i < 0 || new_j < 0 || new_i >= n || new_j >= m) continue;

                // check if max(updated) height diff is smaller or not. if yes then update

                int new_h_dif = max(height, abs(h[new_i][new_j] - h[i][j]));

                if (new_h_dif < min_h[new_i][new_j])
                {
                    min_h[new_i][new_j] = new_h_dif;
                    pq.push({new_i, new_j, new_h_dif});
                }
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