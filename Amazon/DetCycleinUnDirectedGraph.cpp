#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_map<int, bool> vis; // we can use vector also

    bool isCyclic(int N, vector<int> G[])
    {
        // saare nodes pe check kro if we can form a cycle
        for (int i = 1; i < N; i++)
        {
            if (vis[i] == false)
            {
                // as of now we are taking parent node as -1
                if (dfs(G, i, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<int> Graph[], int node, int parent)
    {
        vis[node] = true;
        bool is_true = false;
        for (auto &ch : Graph[node])
        {
            if (vis[ch] && ch == parent)
            {
                // chils has a connection to parent but we don't want this cycle so we ignore
                continue;
            }

            if (vis[ch])
            {
                // alreaedy visisted so it forms a cycle
                return true;
            }
            else
            {
                // not visited
                // if we found any single child node having cycles we return true
                if (dfs(Graph, ch, node))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

void addEdge(vector<int> Graph[], int u, int v)
{
    Graph[u].push_back(v);
    Graph[v].push_back(u);
}

int main()
{

    int V = 6;

    vector<int> Graph[V];
    addEdge(Graph, 0, 1);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 3, 5);
    addEdge(Graph, 4, 5);

    Solution obj;

    if (obj.isCyclic(V, Graph))
        cout << "\nCycle Detected"
             << "\n";
    else
        cout << "No Cycle Detected";

    return 0;
}