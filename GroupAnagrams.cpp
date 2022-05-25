// Shibam Debnath
// May 25,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    // to store ans 
    vector<vector<string>> ans;
    // we are storing each sorted string(ansgrams) as key and inserting all strings that gives our anagram 
    unordered_map<string, vector<string>> mp;

    int n = strs.size();
    for (int i = 0; i < n; i++)
    {
        //storing actual string before sorting it 
        string a = strs[i];
        //sorting each string 
        sort(strs[i].begin(), strs[i].end());
        // push to unordered map 
        mp[strs[i]].push_back(a);
    }

    for (auto &x : mp)
    {
        // for each anagram push to vector of string 
        ans.push_back(x.second);
    }
    return ans;
}

int main()
{
    // Main function goes here
    return 0;
}