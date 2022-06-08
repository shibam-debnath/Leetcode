// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mp;
        int max_freq = -1;
        for (auto &x : tasks)
        {
            mp[x]++;
            // calculate the highest freq
            if (mp[x] > max_freq)
            {
                max_freq = mp[x];
            }
        }
        // NOTE : least time req depends on the char with highest freq not on the smaller freq
        // this stores how many characters are there with highest freq .
        int highest_freq_char_count = 0;

        for (auto i : mp)
        {
            if (i.second == max_freq)
            {
                highest_freq_char_count++;
            }
        }
        // Lower bound of this problem is this -
        // take your copy and pen ,go through 1/2 test cases and you'll definitely find what this logic is (Greedy)
        int ans1 = (n + 1) * (max_freq - 1) + highest_freq_char_count;
        // but what if we have this condition

        // [ "A", "A", "A", "B", "B", "B", "C", "C", "C", "D", "D", "E" ]
        // 2 or 0

        // here ans doesn't depend on max count
        // here we need to check the upper bound That is, what if we don't have any idle time units, what is the answer then?

        int ans2 = tasks.size();
        return max(ans1, ans2);
    }
};

int main()
{
    // Main function goes here
    return 0;
}