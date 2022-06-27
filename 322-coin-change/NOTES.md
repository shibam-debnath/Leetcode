int n = coins.size();
int dp[n + 1][t + 1];
​
for (int i = 0; i <= t; i++)
{
dp[0][i] = INT_MAX - 1;
}
for (int j = 1; j <= n; j++)
{
dp[j][0] = 0;
}
for (int i = 1; i <= t; i++)
{
if (i % coins[0] == 0)
{
dp[1][i] = i / coins[0];
}
else
{
dp[1][i] = INT_MAX - 1;
}
}
​
for (int i = 2; i <= n; i++)
{
for (int j = 1; j <= t; j++)