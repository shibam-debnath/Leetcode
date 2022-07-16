// Shibam Debnath
// May 17,2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> a;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            sum2 = nums[l] + nums[r];
            if (sum2 + nums[i] > 0)
            {
                r--;
            }
            else if (sum2 + nums[i] < 0)
            {
                l++;
            }
            else
            {

                a = {nums[i], nums[l], nums[r]};
                ans.push_back(a);

                while (l < r && nums[l] == a[1])
                {
                    l++;
                }
                while (l < r && nums[r] == a[2])
                {
                    r--;
                }
                a.clear();
            }
        }
    }

    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
