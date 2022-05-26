// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> merge(vector<vector<int>> &v)
{
    sort(v.begin(), v.end());

    vector<vector<int>> ans;
    ans.push_back(v[0]);

    int a = ans[0][0];
    int b = ans[0][1];

    int k = 0;

    for (int i = 1; i < v.size(); i++)
    {

        if (b >= v[i][0])
        {
            ans[k][1] = max(v[i][1], b);
            ans[k][0] = min(v[i][0], a);

            a = ans[k][0];
            b = ans[k][1];
        }
        else
        {

            ans.push_back({v[i][0],
                           v[i][1]});
            k++;
            a = ans[k][0];
            b = ans[k][1];
        }
    }
    return ans;
}
int main()
{
    // Main function goes here
    return 0;
}