// Shibam Debnath
// May 20,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void combinationUtil(int arr[], int new_arr[], int start, int end, int index, int r)
{
    // base case
    if (index == 3)
    {
        for (int i = 0; i < r; i++)
        {
            cout << new_arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    // recursion logic
    for (int j = start; j < (end - start) - r; j++)
    {
        while (arr[j] == arr[j + 1])
        {
            j++;
        }
        new_arr[index] = arr[j];
        combinationUtil(arr, new_arr, start + 1, end, index + 1, r);
    }
}

void printCombination(int arr[], int n, int r)
{
    int new_arr[n]; // to store the possible combinations
    sort(arr, arr + n);

    combinationUtil(arr, new_arr, 0, n - 1, 0, r);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr, n, r);
}
