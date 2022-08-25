class Solution
{
    public:
    int old_c = 0;
    
        void dfs(vector<vector < int>> &img, int i, int j, int c)
        {
            int n = img.size();
            int m = img[0].size();

            if (i < 0 || j < 0 || i == n || j == m || img[i][j] == c || img[i][j] != old_c )
            {
                return;
            }

           	// update
            img[i][j] = c;

           	//traverse all neighbours
            dfs(img, i - 1, j, c);
            dfs(img, i + 1, j, c);
            dfs(img, i, j - 1, c);
            dfs(img, i, j + 1, c);
        }
    
    vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int newColor)
    {
        old_c = image[sr][sc];
        dfs(image, sr, sc, newColor);
        return image;
    }
};