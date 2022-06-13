// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &t)
    {
        int n = t.size();
        // we'll start from the last index -1 and start storing sum of that val + min(possible val from two lower levels) int that val itself
        // this way we'll get the ans stored in first index ie t[0][0]
        // bottom up
        for (int i = n - 2; i >= 0; i++)
        {
            for (int j = 0; j < t[i].size(); j++)
            {
                t[i][j] = t[i][j] + min(t[i + 1][j], t[i + 1][j + 1]);
            }
        }
        return t[0][0];
    }
};

int main()
{
    // Main function goes here
    return 0;
}