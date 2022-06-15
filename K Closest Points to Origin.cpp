// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (auto &pts : points)
        {
            int x = pts[0];
            int y = pts[1];

            int d = x * x + y * y;
            pq.push({d, {x, y}});
        }

        vector<int> v;
        for (int i = 0; i < k; i++)
        {
            v.clear();
            v.push_back(pq.top().second.first);
            v.push_back(pq.top().second.second);

            ans.push_back(v);
            pq.pop();
        }

        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}