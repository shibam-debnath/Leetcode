// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        for (int i = k; i < n; i++)
        {
            pq.push({nums[i], i});

            //! if any element is there with index i which should not be present in the current sliding window then return
            // current window is from [i-k+1 , i]
            // bas top mein aisa value laao jo range mein exist krta ho
            while (!(pq.top().second > i - k))
            {
                pq.pop();
            }

            // insert the max element
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}