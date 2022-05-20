// Shibam Debnath
// May 19,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void merge(vector<int> &nums, int m, vector<int> &a2, int n)
{

    int i = m - 1, j = n - 1, k = n + m - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums[i] > a2[j])
        {
            nums[k] = nums[i];
            i--;
            k--;
        }
        else
        {
            nums[k] = a2[j];
            j--;
            k--;
        }
    }
    while (j >= 0)
    {
        nums[k] = a2[j];
        j--;
        k--;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
