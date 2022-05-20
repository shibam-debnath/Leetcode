// Shibam Debnath
// May 19,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int removeDuplicates(vector<int> &nums)
{
    int i = 0, j = 1, temp;
    if (nums.size() == 1 || nums.size() == 0)
    {
        return nums.size();
    }
    while (j < nums.size())
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
        j++;
    }

    return i + 1;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
