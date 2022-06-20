// C++ implementation
#include <bits/stdc++.h>
using namespace std;

// function to return the count
int count_greater(int arr[], int n)
{
    int mini = arr[n - 1];
    int ans = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > mini)
        {
            // cout << arr[i];
            ans++;
        }
        else
        {
            if (arr[i] < mini)
            {
                // update mini
                mini = arr[i];
            }
        }
    }
    return ans;
}

// Driver code
int main()
{
    int arr[] = {3, 9, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(int);

    cout << count_greater(arr, n) << endl;

    return 0;
}
