// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void DFS(int v)
    {
        vis[v] = true;
        for (auto &x : adj[v])
        {
            if (!vis[x])
            {
                DFS(x);
            }
        }
    }
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> vis;
    int findCircleNum(vector<vector<int>> &e)
    {
        for (int i = 0; i < e.size(); i++)
        {
            for (int j = 0; j < e[0].size(); j++)
            {
                if (e[i][j] == 1 && i != j)
                { // i!=j to avoid self loop
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < e.size(); i++)
        {
            if (vis[i])
            {
                continue;
            }
            count++;
            DFS(i);
        }

        return count;
    }
};

int main()
{
    // Main function goes here
    return 0;
}