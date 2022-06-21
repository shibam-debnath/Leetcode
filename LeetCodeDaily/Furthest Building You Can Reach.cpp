// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        // mIn heap to help us build building using BRICKS only
        priority_queue<int, vector<int>, greater<int>> pq;

        int ans = 0;
        for (int i = 1; i < heights.size(); i++)
        {
            int d = heights[i] - heights[i - 1];
            // keep inserting the differences for no of ladder times
            
            
            if(d>0){

                pq.push(d);

                if(pq.size() > ladders){
                    // ladders are out of stock so now use  bricks now

                    if(bricks-pq.top()>=0){
                        bricks = bricks - pq.top();
                        pq.pop();
                    }
                    else{
                        return i;
                    }
                }
            }
        }

        // if saare cross kr liye 

        return heights.size();
    }
};
int main()
{
    // Main function goes here
    return 0;
}