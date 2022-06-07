// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map;
        vector<int> ans;
        stack<int> s;
        for (auto x : nums2)
        {
            // if s is not empty and wo pehle wale(s.top()) se bada h then keep inserting both in map
            if (!s.empty() && x > s.top())
            {
                while (!s.empty())
                {
                    map[s.top()] = x;
                    s.pop();
                }
            }
            s.push(x);
        }

        for (auto &y : nums1)
        {
            if (map[y])
            {
                ans.push_back(map[y]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}