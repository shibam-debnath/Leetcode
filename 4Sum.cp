// Shibam Debnath
// May 20,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> ans;
    vector<vector<int>> mat;
    
    
    for (int i = 0; i <= nums.size() - 4; i++)
    {
        if (nums[i] == nums[i-1] && i!= 0)
        {
            continue;
        }
        for (int j = i + 1; j < nums.size() - 4 + 1; j++)
        {
            int l = j + 1, r = n - 1;
            if (nums[j] == nums[j - 1] && j != i+1)
            {
                continue;
            }

            //** Find two numbers such that sum is x;
            int x = target - nums[i] + nums[j];
            while (l<r)
            {
                // if  sum is greater than x then right ko decrease karo
                if(nums[l]+nums[r] > x){
                    r--;
                }
                else if (nums[l] + nums[r] < x){
                    l++;
                }
                else{
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(nums[l]);
                    ans.push_back(nums[r]);
                   
                    mat.push_back(ans);
                    ans.clear();

                    
                    l++;
                    r--;
                    while (nums[l] == nums[l-1] && l < n)
                    {
                        l++;
                    }
                    while (nums[r] == nums[l+1] && l > 0)
                    {
                        r--;
                    }
                }
            }
        }
    }

    return mat;
}

int main()
{
    int test;
    cin >> test;
    int a;
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    fourSum(arr, test);
    return 0;
}
