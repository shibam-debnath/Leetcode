// Shibam Debnath
// May 21,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Runtime: 383 ms, faster than 50.08% of C++ online submissions for Max Value of Equation.
// Memory Usage: 92.4 MB, less than 44.99% of C++ online submissions for Max Value of Equation.

int findMaxValueOfEquation(vector<vector<int>> &pt, int k)
{
    int n = pt.size();
    // since we want to maximize Yi-Xi so this should
    // be our first parameter of priority queue
    priority_queue<pair<int, int>> pq;
    pq.push({pt[0][1] - pt[0][0], pt[0][0]});

    int ans = 0;
    int sum = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        ans = pt[i][0] + pt[i][1];
        while (!pq.empty && (pt[i][0] - pq.top().second) > k)
        {
            pq.pop(); // if this diff is greater than our pq.top() next walo se to bada hoga hi since it is already in increasing order
        }
        if (!pq.empty())
        {
            // store max sum here
            sum = max(sum, ans + pq.top().first);
        }
        pq.push({pt[i][1] - pt[i][0], pt[i][1]}); // keep pushing new possibilities to maximize yi-xi
    }

    return sum;
}

// ** This approach is fine but it gives tle for long test cases

// int findMaxValueOfEquation(vector<vector<int>> &pt, int k)
// {
//     int n = pt.size();
//     int sum = INT_MIN;
//     for (int i = 0; i < n - 1; i++)
//     {
//         int j = i + 1;
//         if (pt[j][0] - pt[i][0] > k)
//         {
//             continue;
//         }
//         while (j < n && pt[j][0] - pt[i][0] <= k)
//         {
//             sum = max(sum, pt[j][1] + pt[i][1] + abs(pt[j][0] - pt[i][0]));
//             j++;
//         }
//     }

//     return sum;
// }

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    return 0;
}
