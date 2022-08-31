class Solution
{
public:
    // to check the flow of water in each ocean
    vector<vector<bool>> pacific, atlantic;
    // to store ans
    vector<vector<int>> ans;

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
    {
        if (h.empty())
            return ans;

        int n = h.size();
        int m = h[0].size();

        pacific.resize(n, vector<bool>(m, false));
        atlantic.resize(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++)
        {
            // dfs for pacific (top edge)
            dfs(h, pacific, 0, i);
            
            // dfs for atlantic (bottom edges)
            dfs(h, atlantic, n - 1, i);
            
        }
        
        // similar for left and right edge
        for (int i = 0; i < n; i++)
        {
            dfs(h, pacific, i, 0);
            dfs(h, atlantic, i, m - 1);
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>> &h, vector<vector<bool>> &vis, int i, int j)
    {
        int n = h.size();
        int m = h[0].size();

        if (vis[i][j])
            return;

        vis[i][j] = true;
        
        // if this height is intersection point for both oceans that means from here water can flow to both oceans 
        if(pacific[i][j] and atlantic[i][j]){
            ans.push_back({i,j});
        } 
        
        vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
        
        for(auto &d : dir){
            
            int x = i+d[0];
            int y = j+d[1];
            
            // go to next cell if and only if height is greater than current cell's height
            if(x>=0 and y>=0 and x<n and y<m and h[x][y]>=h[i][j]){
                dfs(h,vis,x,y);
            }
        }
    }
};