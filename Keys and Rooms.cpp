// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
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
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        dfs(rooms, 0);
        // start from first room and start opening other rooms
        for (int i = 0; i < n; i++)
        {
            // traverse and if you found that this room is not visited then return false
            if (!vis[i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    // Main function goes here
    return 0;
}