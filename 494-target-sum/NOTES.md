class Solution {
public:
int findTargetSumWays(vector<int> &arr, int diff)
{
int n = arr.size();
int sum = 0;
for (int i = 0; i < n; i++)
{
sum += arr[i];
}
​
int t = (diff + sum) / 2;
​
if (n == 0 || t > sum || (diff+sum)%2 != 0)
{
return 0;
}
t = abs(t);
​
// Dp matrix
int ans[n + 1][t + 1];
​
// *Base Case or initialization
​
for (int i = 1; i <= t; i++)
{
ans[0][i] = 0;