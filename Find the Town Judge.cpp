// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> trust_count(n + 1, 0);

        for (auto &x : trust)
        {
            trust_count[x[0]]--;
            trust_count[x[1]]++;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (trust_count[i] == n - 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    // Main function goes here
    return 0;
}