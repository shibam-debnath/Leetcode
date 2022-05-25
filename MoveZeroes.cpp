//Shibam Debnath
//May 23,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void moveZeroes(vector<int> &nums)
{
    vector<int> v;
    int c = 0;
    for(auto &x : nums){
        if(x==0){
            c++;
        }
        else{
            v.push_back(x);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        nums[i] = v[i];
    }
    for (int i = 0; i < c; i++)
    {
        nums[nums.size() + i] = 0;
    }
    
    
}
int main() {
    //Main function goes here
    return 0;
}