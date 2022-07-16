// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
#define INF INT_MAX
    int findTheCity(int n, vector<vector<int>> &edges, int t)
    {
        // use floyd warshall algo
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Initialize the solution matrix ( v-> no of cities)
        for (vector<int> e : edges)
        {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            // Pick all vertices as source one by one
            for (int i = 0; i < n; i++)
            {
                // Pick all vertices as destination for the above picked source
                for (int j = 0; j < n; j++)
                {
                    // If through k we can have a short path from i to j then update that else ignore
                    //     note such that both aren't inf             i->k dis      k->j dis
                    if ((dist[i][k] != INF && dist[k][j] != INF) && (dist[i][k] + dist[k][j]) < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int cityCount = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int len = 0;
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < n; j++)
            {

                if (dist[i][j] <= t)
                    len++;
                // cout << dist[i][j] << "  ";
            }
            cout << endl;

            if (len <= cityCount)
            {
                ans = i;
                cityCount = len;
            }
        }

        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}