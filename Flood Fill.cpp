// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int old_c = 0;

    void dfs(vector<vector<int>> &img, int i, int j, int c)
    {
        int n = img.size();
        int m = img[0].size();

        if (i < 0 || j < 0 || i == n || j == m || img[i][j] != old_c)
        {
            return;
        }

        // update
        img[i][j] = c;

        // traverse all neighbours
        dfs(img, i - 1, j, c);
        dfs(img, i + 1, j, c);
        dfs(img, i, j - 1, c);
        dfs(img, i, j + 1, c);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        old_c = image[sr][sc];
        //if old color = new color we don't have to update anything 
        //! NOTE : instead of writing this condition here write in dfs function (to make it fast)
        if (old_c == newColor)
        {
            return image;
        }
        //update using dfs 
        dfs(image, sr, sc, newColor);
        return image;
    }
};

int main()
{
    // Main function goes here
    return 0;
}