class Solution
{
    public:
        void DFS(int v,vector<vector < int>>& grid,unordered_map<int, bool> &vis)
        {
            vis[v] = true;
            for (int i=0;i<grid.size();i++)
            {
                if (vis[i]==false && grid[v][i]==1)
                {
                    DFS(i,grid,vis);
                }
            }
        }

    int findCircleNum(vector<vector < int>> e)
    {
        int count = 0;
        unordered_map<int, bool> vis;
        for (int i = 0; i < e.size(); i++)
        {
            if (vis[i])
            {
                continue;
            }
            count++;
            DFS(i,e,vis);
        }

        return count;
    }
};