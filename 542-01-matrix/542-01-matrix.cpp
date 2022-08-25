class Solution
{
public:
    
    int dr[4] = {-1, +1, 0, 0};
    int dc[4] = {0,0,+1,-1};

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q; 

        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (mat[r][c] == 0) q.emplace(r, c);
                else mat[r][c] = -1; 
            }
        }
   
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
        
            for (size_t i = 0; i < 4; i++)
            {
                int newR = x.first + dr[i]; 
                int newC = x.second + dc[i];
               
                if(newR < 0 || newC < 0 || newR >= m || newC >= n || mat[newR][newC] != -1){
                    continue;
                }
                mat[newR][newC] = 1 + mat[x.first][x.second];
                q.push({newR, newC});
            }
        }

        return mat;
    }
};