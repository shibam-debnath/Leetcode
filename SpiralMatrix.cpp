// Shibam Debnath
// May 18,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int dir = 0, l = 0, r = m - 1, t = 0, b = n - 1;
    int no = 1;
    while (l < r)
    {
        if (dir == 0 && l >= 0 && r <= m - 1)
        {
            for (int i = l; i < r; i++)
            {
                matrix[t][i] = no;
                no++;
            }
            t++;
            dir = (dir + 1) % 4;
        }
        else if (dir == 1 && t >= 0 && b <= n - 1)
        {
            for (int j = t; j < b; j++)
            {
                matrix[j][r] = no;
                no++;
            }
            r--;
        }
        else if (dir == 2 && l >= 0 && r <= m - 1)
        {
            for (int i = r; i >= 0; i--)
            {
                matrix[b][i] = no;
                no++;
            }
            b--;
        }
        if (dir == 3 && t >= 0 && b <= m - 1)
        {
            for (int j = b; j >= t; j--)
            {
                matrix[j][l] = no;
                no++;
            }
            l++;
        }
        dir = (dir + 1) % 4;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
    }
    return 0;
}
