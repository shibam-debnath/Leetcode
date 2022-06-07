// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> v(n, 0); // store ans
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            // if no is greater than equal to the top temp then keep poping
            while (!s.empty() && temperatures[i] >= temperatures[s.top()])
            {
                s.pop();
            }
            // stack is not empty means we have atleast one higher temp day
            if (!s.empty())
            {
                int dis = s.top() - i;
                v[i] = dis;
            }

            s.push(i);
        }

        return v;
    }
};

int main()
{
    // Main function goes here
    return 0;
}