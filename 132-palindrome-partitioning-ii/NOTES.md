With Explaination
​
```
class Solution
{
public:
vector<vector<int>> dp;
​
int minCut(string s)
{
int N = s.size();
// initialisation with -1
dp.resize(N + 1, vector<int>(N + 1, -1));
​
return MCM(s, 0, N - 1);
}
​
​
int MCM(string &s, int i, int j)
{
// base case
if (i >= j)
{
return 0;
}
​