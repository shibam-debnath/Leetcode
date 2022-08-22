// Shibam Debnath
// July,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1e5 + 10
#define endl '\n'

bool sub_string(string &s, unordered_map<char, int> &mp)
{
    for (auto c : s)
    {
        if (mp.find(c) == mp.end() || mp[c] == 0)
            return false;
        else
        {
            mp[c]--;
        }
    }
}

bool solve(vector<string> &v, unordered_map<char, int> &mp)
{
    for (auto ss : v)
    {
        if (sub_string(ss, mp) == false)
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while (test--)
    {
        string par1, par2;
        cin >> par1 >> par2;

        unordered_map<char, int> mp;
        for (auto c : par1)
        {
            mp[c]++;
        }
        for (auto c : par2)
        {
            mp[c]++;
        }

        int n;
        cin >> n;

        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (solve(v, mp))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}