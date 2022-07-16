#include "bits/stdc++.h"
#define int long long

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

int n, m, timer = 0, compid;

vector<pair<int, int>> g[MAXN];
bool used[MAXN], isBridge[MAXM];
int comp[MAXN], tin[MAXN], minAncestor[MAXN];
map<int, int> freq;
long long ans = 0;

vector<int> tree[MAXN]; // Store 2-edge-connected component tree.(Bridge tree).

void dfs(int v, int p)
{
    tin[v] = minAncestor[v] = ++timer;
    used[v] = 1;
    for (auto &e : g[v])
    {
        int to, id;
        tie(to, id) = e;
        if (to == p)
            continue;
        if (used[to])
        {
            minAncestor[v] = min(minAncestor[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            minAncestor[v] = min(minAncestor[v], minAncestor[to]);
            if (minAncestor[to] > tin[v])
            {
                isBridge[id] = true;
            }
        }
    }
}

void dfs1(int v, int p)
{
    used[v] = 1;
    comp[v] = compid;
    freq[compid]++;
    for (auto &e : g[v])
    {
        int to, id;
        tie(to, id) = e;

        if (isBridge[id])
        { // avoid traversing from this edge. so we get full component.
            continue;
        }
        if (used[to])
        {
            continue;
        }
        dfs1(to, v);
    }
}

vector<pair<int, int>> edges;

void addEdge(int from, int to, int id)
{
    g[from].push_back({to, id});
    g[to].push_back({from, id});
    edges[id] = {from, to};
}

void initB()
{

    for (int i = 0; i <= compid; ++i)
        tree[i].clear();
    for (int i = 1; i <= n; ++i)
        used[i] = false;
    for (int i = 1; i <= m; ++i)
        isBridge[i] = false;

    timer = 0;
    compid = 0;
}

void bridge_tree()
{

    initB();

    dfs(1, -1); // Assuming graph is connected.

    for (int i = 1; i <= n; ++i)
        used[i] = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!used[i])
        {
            dfs1(i, -1);
            ++compid;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        if (isBridge[i])
        {
            int u, v;
            tie(u, v) = edges[i];
            // deb(u, v);
            // connect two componets using edge.
            int comp_u = comp[u], comp_v = comp[v];
            long long comp_u_sz = freq[comp_u], comp_v_sz = freq[comp_v];
            ans += comp_u_sz * 1ll * comp_v_sz;
            tree[comp[u]].push_back(comp[v]);
            tree[comp[v]].push_back(comp[u]);
        }
    }
}

void init()
{
    edges.clear();
    edges.resize(m + 1);
    for (int i = 1; i <= n; ++i)
        g[i].clear();
}

void solve()
{
    cin >> n >> m;

    init();
    freq.clear();

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        --u, --v;
        cin >> u >> v;
        addEdge(u, v, i);
    }
    ans = 0ll;

    bridge_tree();
    cout << ans << "\n";
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}