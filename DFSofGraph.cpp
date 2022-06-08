
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, bool> vis;
    unordered_map<int, list<int>> adj;

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void DFS(int v);
};

void Graph::DFS(int v)
{
    vis[v] = true;
    cout << v << "  ";
    for (auto &x : adj[v])
    {
        if (!vis[x])
        {
            DFS(x);
        }
    }
}

// Driver code
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}
