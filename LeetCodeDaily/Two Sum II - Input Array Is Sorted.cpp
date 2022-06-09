// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> mp;
        int c = 1;
        for (auto &x : numbers)
        {

            int t = target - x;
            if (mp.find(t) != mp.end())
            {
                int pos = mp.find(t)->second;
                return {pos, c};
            }
            mp[x] = c;
            c++;
        }
        return numbers;
    }
};

int main()
{
    // Main function goes here
    return 0;
}