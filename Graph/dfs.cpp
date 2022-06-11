//Shibam Debnath
//June ,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<int, bool> vis;

void dfs(vector<vector<int>> &rooms, int v)
{
    vis[v] = true;
    for (auto &x : rooms[v])
    {
        if (!vis[x])
        {
            dfs(rooms, x);
        }
    }
}

int main() {
    //Main function goes here
    return 0;
}