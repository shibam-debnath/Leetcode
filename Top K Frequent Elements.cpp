// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto &x : nums)
        {
            mp[x]++;
        }
        nums.clear();
        priority_queue<pair<int, int>> pq;

        for (auto V : mp)
        {
            pq.push({V.second, V.first});
        }

        for (int i = 0; i < k; i++)
        {
            int a = pq.top().second;
            nums.push_back(a);
            pq.pop();
        }

        return nums;
    }
};

int main()
{
    // Main function goes here
    return 0;
}