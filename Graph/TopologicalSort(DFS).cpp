// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
private:
    void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &s)
    {
        vis[node] = true;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, s);
            }
        }
        // pehle childs push honge in stack
        s.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, s);
            }
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}