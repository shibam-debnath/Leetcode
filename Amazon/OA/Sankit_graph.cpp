// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;

// variables to be used
// in both functions
vector<int> graph[N];
vector<int> cycles[N];
vector<bool> vis;

int partOfCycle(int node, int par)
{
}

int solve(int node, int par)
{

    int ans = 0;

    // first mark the node visited
    vis[node] = true;

    for (auto ch : graph[node])
    {

        if (partOfCycle(ch, node))
        {          // check if this node is a part of cycle or not
            // ans += ; // no of nodes in that cycle
        }
        else if (!vis[ch])
        {
            ans++;
        }
        // else if(vis[ch] && ch==parent){
        //     continue;
        // }
    }
}

void dfs_cycle(int u, int p, int color[],
               int mark[], int par[], int &cyclenumber)
{

    // already (completely) visited vertex.
    if (color[u] == 2)
    {
        return;
    }

    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1)
    {

        cyclenumber++;
        int cur = p;
        mark[cur] = cyclenumber;

        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u)
        {
            cur = par[cur];
            mark[cur] = cyclenumber;
        }
        return;
    }
    par[u] = p;

    // partially visited.
    color[u] = 1;

    // simple dfs on graph
    for (int v : graph[u])
    {

        // if it has not been visited previously
        if (v == par[u])
        {
            continue;
        }
        dfs_cycle(v, u, color, mark, par, cyclenumber);
    }

    // completely visited.
    color[u] = 2;
}

// add the edges to the graph
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Function to print the cycles
void printCycles(int edges, int mark[], int &cyclenumber)
{

    // push the edges that into the
    // cycle adjacency list
    for (int i = 1; i <= edges; i++)
    {
        if (mark[i] != 0)
            cycles[mark[i]].push_back(i);
    }

    // print all the vertex with same cycle
    for (int i = 1; i <= cyclenumber; i++)
    {
        // Print the i-th cycle
        cout << "Cycle Number " << i << ": ";
        for (int x : cycles[i])
            cout << x << " ";
        cout << endl;
    }
}

// Driver Code
int main()
{

    // add edges
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 2);
    addEdge(5, 3);

    // arrays required to color the
    // graph, store the parent of node
    int color[N];
    int par[N];

    // mark with unique numbers
    int mark[N];

    // store the numbers of cycle
    int cyclenumber = 0;
    int edges = 13;

    // call DFS to mark the cycles
    dfs_cycle(1, 0, color, mark, par, cyclenumber);

    // function to print the cycles
    printCycles(edges, mark, cyclenumber);
}
