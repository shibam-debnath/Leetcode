//Shibam Debnath
//June ,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n1 = accumulate(gas.begin(), gas.end(), 0);
        int n2 = 0, curr_fuel = 0, max_pos = INT_MIN;
        for (int i = 0; i < cost.size(); i++)
        {
            curr_fuel += gas[i] - cost[i];
            // we start from left and jab fuel(remaining fuel) khtm ho jaye uske next point se restart karo gari . 
            if (curr_fuel < 0)
            {
                curr_fuel = 0;
                max_pos = (i+1)%cost.size();
            }
            n2 += cost[i];
        }

        if(n2>n1){
            return -1;
        }

        return max_pos;
    }
};

int main() {
    //Main function goes here
    return 0;
}