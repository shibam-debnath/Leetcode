//Shibam Debnath
//May 16,2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> twoSum(vector<int> &nums, int target)
{ 
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++)
    {
        int b = nums[i];
        int a = target - b;
        if ((seen.find(a)) != seen.end())
        {
            return {seen[a], i};
        }
        seen[b] = i;
    }
    return {};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    
    return 0;
}
