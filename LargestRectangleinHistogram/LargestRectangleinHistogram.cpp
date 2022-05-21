// Shibam Debnath
// May 21,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int largestRectangleArea(vector<int> &h)
{
    int n = heights.size();
    if (n == 0)
        return 0;
    int maxArea = 0;
    vector<int> left(n);  // fill left boundary
    vector<int> right(n); // fill right boundary

    left[0] = -1;
    right[n - 1] = n;

    for (int i = 1; i < n; i++)
    {
        int prev = i - 1; // comparing the heights
        while (prev >= 0 && heights[prev] >= heights[i])
        {
            prev = left[prev];
        }
        left[i] = prev;
    }
    // for right
    for (int i = n - 2; i >= 0; i--)
    {
        int prev = i + 1;
        while (prev < n && heights[prev] >= heights[i])
        {
            prev = right[prev];
        }
        right[i] = prev;
    }
    // finally calculate area for each position
    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}

// int largestRectangleArea(vector<int> &h)
// {
//     int low = 0, area = h[0], area_1 = h[0], max_area = h[0], min_h = 0, area_2 = h[0];
//     for (int i = 1; i < h.size(); i++)
//     {
//         if (h[i - 1] < h[i])
//         {

//             low = h[i - 1];
//             min_h = low;
//             cout << low << "  ";
//         }
//         else
//         {
//             low = h[i];
//             min_h = low;
//         }
//         area_2 = max(h[i], low * 2); // with last wala
//         // cout << area_2 << "  ";
//         if (i != 1)
//         {
//             area_1 = max(h[i], i * min_h); // ekdam pehle se
//             cout << area_1 << "  ";
//         }
//         area = max(area_1, area_2);
//         // max_area = max(max_area, area);
//     }

//     return area > h[0] ? area : h[0];
// }
int main()
{
    // Main function goes here
    return 0;
}