// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int furthestBuilding(vector<int> &h, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 1;
        for (i = 1; i < h.size(); i++)
        {
            int d = h[i] - h[i - 1];
            if (d > 0)
            {
                pq.push(d);

                // keep pushing untill ladders khtm ho jaaye
                if (pq.size() > ladders)
                {
                    // aur brick se kaam nehi hoga
                    if (pq.top() > bricks)
                    {
                        return i - 1;
                    }
                    else
                    {
                        bricks -= pq.top();
                        pq.pop();
                    }
                }
            }
        }
        return h.size() - 1;
    }
};

int main()
{
    // Main function goes here
    return 0;
}