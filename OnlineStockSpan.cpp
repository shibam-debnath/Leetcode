// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class StockSpanner
{
public:
    stack<int> s;

    vector<int> v;
    int c = 0; // only for index

    StockSpanner()
    {
    }

    int next(int price)
    {
        int ans = 0;
        v.push_back(price);
        while (!s.empty() && price >= v[s.top()])
        {
            s.pop();
        }
        if (!s.empty())
        {
            ans = c - s.top();
        }
        else
        {
            // stack empty means all elements on left are smaller so return c+1
            ans = c + 1;
        }
        s.push(c); // price ka index push
        c++;
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}