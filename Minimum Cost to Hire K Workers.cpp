// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({(double)wage[0], quality[0]});
        double ref = quality[0];
        int mon = wage[0];

        for (int i = 1; i < quality.size(); i++)
        {
            double salary = ((double)quality[i] / (double)ref) * (double)mon;
            if (salary > wage[i])
            {
                pq.push({salary, quality[i]});
                ref = quality[i];
                mon = wage[i];
            }
        }

        double ans;
        for (int i = 0; i < k; i++)
        {
            ans += pq.top().first;
        }

        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}