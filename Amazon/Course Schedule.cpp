// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<vector<int>> G;
    vector<bool> vis;
    vector<bool> dfs_vis;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        // build the graph first using given info
        build_graph(numCourses, prerequisites);

        // resize vissited and dfs_visited array
        vis.resize(numCourses, false);
        dfs_vis.resize(numCourses, false);

        // check if there is a cycle or not from any course. If it has then we can't complete the course
        for (int i = 0; i < numCourses; i++)
        {
            // cycle found == we can't complete our course
            if (has_cycle(i))
            {
                return false;
            }
        }
        return true;
    }

    void build_graph(int numCourses, vector<vector<int>> &prerequisites)
    {
        G.resize(numCourses);
        for (auto &v : prerequisites)
        {
            G[v[0]].push_back(v[1]);
        }
    }

    bool has_cycle(int node)
    {
        // mark as visited
        vis[node] = true;
        dfs_vis[node] = true;

        // go to it's childs and check if there is a cycle or not
        for (auto &child : G[node])
        {
            if (!vis[child])
            {
                // check if child has a cycle
                if (has_cycle(child))
                {
                    return true;
                }
            }
            else
            {
                // if vis[child] as well as dfs_vis[child] == we found a cycle
                if (dfs_vis[child])
                {
                    return true;
                }
            }
        }

        // while returning make dfs_vis as false
        dfs_vis[node] = false;
        // if we didn't find a cycle then return false
        return false;
    }
};

int main()
{
    // Main function goes here
    return 0;
}