// C++ program for the above approach

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Time Complexity : O(N *log N)
// Auxiliary Space : O(N)

int numberOfSubarrays(int arr[], int n)
{
    vector<pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp.push_back({arr[i], i});
    }

    sort(mp.begin(), mp.end());

    int c = 1;
    for (int i = 1; i < n; i++)
    {
        if (mp[i].second == mp[i - 1].second + 1)
        {
            // already sorted
        }
        else
        {
            c++;
        }
    }

    return c;
}

// Driver Code
int main()
{
    int arr[] = {6, 3, 4, 2, 1};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << numberOfSubarrays(arr, N);

    return 0;
}
