// Shibam Debnath
// May 17,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxArea(vector<int> &height)
{
    int start = 0;
    int end = height.size() - 1;

    int area = 0;
    while (start < end) // two pointer approach
    {
        area = max(area, (end - start) * min(height[start], height[end]));
        if (height[start] < height[end])
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return area;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    return 0;
}
