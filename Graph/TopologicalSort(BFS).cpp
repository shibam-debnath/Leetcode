// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    queue<int> q;
    vector<int> res;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto &it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        res.push_back(node);

        for (auto &ch : adj[node])
        {
            indegree[ch]--;
            if (indegree[ch] == 0)
                q.push(ch);
        }
    }

    return res;
}

int main()
{
    // Main function goes here
    return 0;
}