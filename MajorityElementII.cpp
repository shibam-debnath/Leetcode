//Shibam Debnath
//May 23,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    int a = n / 3;

    for (int i = 0; i < n;i++)
    {
        mp[nums[i]]++;
        if(mp[nums[i]]> a){
            nums.push_back(nums[i]);
        }
    }
   
    return ans;
}
int main() {
    //Main function goes here
    return 0;
}