// tabulation approach
​
```
class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
int row = grid.size();    // row no
int col = grid[0].size(); // column no
​
int dp[col];
dp[0] = grid[0][0];
//first store the first row
for (int i = 1; i < col; i++)
{
dp[i] = grid[0][i] + dp[i-1];
}
for (int j = 1; j < row; j++)   // this part is very imp
{
dp[0]= grid[j][0] + dp[0];      // update 0th index
for (int i = 1; i < col; i++)
{
dp[i] = grid[j][i] + min(dp[i-1],dp[i]);
}
}
​
return dp[col-1];
}
};
```