// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for(auto &c : s){
            mp[c]++;
        }

        for(auto m:mp){
            pq.push({m.second,m.first});
        }
        s.clear();

        while(!pq.empty()){
            char a = pq.top().second;
            pq.pop();
            char b = pq.top().second;
            pq.pop();

            s += 'a';
            s += 'b';
        }


    }
};

int main()
{
    // Main function goes here
    return 0;
}