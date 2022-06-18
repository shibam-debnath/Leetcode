#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool dfs(vector<int> adj[], int node, int parent)
    {
        vis[node] = true;
        bool is_true = false;
        for (auto &ch : adj[node])
        {
            if (vis[ch] && ch == parent)
            {
                // chils has a connection to parent but we don't want this cycle so we ignore
                continue;
            }

            if (vis[ch])
            {
                cout << ch << " " << node << " " << parent << endl;
                // alreaedy visisted so it can form a cycle
                return true;
            }
            // if we found any single node having cycles we return true
            is_true = is_true || dfs(adj, ch, node);
        }
        return is_true;
    }

public:
    unordered_map<int, bool> vis;
    bool isCyclic(int N, vector<int> adj[])
    {
        // saare nodes pe check kro if we can form a cycle
        for (int i = 1; i < N; i++)
        {
            if (vis[i] == false)
            {
                // cout << i << endl;
                if (dfs(adj, i, -1))
                {

                    return true;
                }
                else
                {
                    continue;
                }
            }
        }
        return false;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{

    int V = 6;

    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    Solution obj;

    if (obj.isCyclic(V, adj))
        cout << "\nCycle Detected"
             << "\n";
    else
        cout << "No Cycle Detected";

    return 0;
}