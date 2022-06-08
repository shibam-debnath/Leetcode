// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> vis;

    bool dfs(int source, int destination)
    {

        vis[source] = true;

        if (source == destination)
        {
            return true;
        }
        bool ans = false;
        for (auto &x : adj[source])
        {
            if (source == destination)
            {
                return true;
            }

            if (vis[x] == false)
            {
                //check all adjascent points and store the ans in a bool var
                ans = ans || dfs(x, destination);
            }
        }

        return ans;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(source, destination);
    }
};

int main()
{
    // Main function goes here
    return 0;
}