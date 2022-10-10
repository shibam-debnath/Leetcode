​
int cityCount = INT_MAX;
int ans = 0;
for (int i = 0; i < n; i++)
{
// cal no of reachable cities
int len = 0;
for (int j = 0; j < n; j++)
{
cout << dist[i][j] << "  ";
if (dist[i][j] <= t)
len++;
}
​
if (len <= cityCount)
{
ans = i;
cityCount = len;
}
}
​
return ans;