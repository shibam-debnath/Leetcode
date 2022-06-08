// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> restoreArray(vector<vector<int>> &a)
{
    unordered_map<int, vector<int>> mp; // to store the adjascency list
    vector<int> v;                      // to store ans
    unordered_map<int, bool> visi;      // to store visited or not

    for (auto &x : a)
    {
        // filling adjascency list
        //  * new learning
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }
    // now find starting point i.e the corner element 
    int start = 0;
    for (auto &z : mp)
    {
        // for any val map.size() is 1 then that is the starting index;
        if (z.second.size() == 1)
        {
            start = z.first;
            break;
        }
    }
    // we have the starting iterator z although to access that we need to declare the iteration outside for loop
    // store first val to vector and mark it visited
    v.push_back(start);
    visi[start] = true;
    //now traverse the graph and keep adding if they are not visited
    for (int i = 0; i < a.size(); i++)
    {
        //first we start from first starting index start and check all its adjascents
        for(auto adj : mp[start]){
            // if they are not visited then keep adding them to ans  
            if (!visi[adj])
            {
                v.push_back(adj);
                visi[adj] = true;
                // traverse all the possible links 
                start = adj;
            }
            
        }
    }
    // return ans
    return v;
}

int main()
{
    // Main function goes here
    return 0;
}