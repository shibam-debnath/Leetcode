// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//* Time Complexity :::  O(2^n *n)   -> 2^n subsets(Recursion) and O(n) for insertion
//* Space Complexity ::: O(2^n *n)

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> a;

    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<vector<int>> combinationSum3(int k, int n)
    {

        int index = 0;
        int k_count = 0;

        func(index, k, n, k_count);

        return ans;
    }
    void func(int ind, int k, int target, int size)
    {
        // ! difference

        if (size == k && target == 0)
        {
            ans.push_back(a);
            return;
        }
        if (size == k)
        {
            return;
        }

        for (int i = ind; i < 9; i++)
        {
            if (arr[i] > target)
                break;

            a.push_back(arr[i]);
            func(i + 1, k, target - arr[i], size + 1);
            a.pop_back();
        }
    }
};

int main()
{
    // Main function goes here
    return 0;
}