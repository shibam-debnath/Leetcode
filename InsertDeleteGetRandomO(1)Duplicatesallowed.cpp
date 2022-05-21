// Shibam Debnath
// May 21,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
class RandomizedCollection
{
public:
    vector<int> v;
    unordered_map<int, unordered_set<int>> mp;

    RandomizedCollection()
    {
        cout << "Hurrah !";
    }

    bool insert(int val)
    {
        bool a = !mp[val].size(); // check

        mp[val].insert(v.size());
        v.push_back(val);
        return a;
    }

    bool remove(int val)
    {
        bool a = mp[val].size(); // check
        if (!a)
        {
            return false; // element is not there direct return cause we don't
            // have to remove
        }

        auto v_val = *mp[val].begin(); // it gives the  first val of the vector/unordered set for mp[val]
        mp[val].erase(v_val);          // wo wala element deleted from mp

        // now lets delete from vector also

        // if mp mein last wala(of vector) val present hein tabhi to delete karenge otherwise nehi karenge
        if (mp[v[v.size() - 1]].size())
        {
            int pos = v[v.size() - 1]; // last element of that vector
            mp[pos].erase(v.size() - 1);
            mp[pos].insert(v_val);
            swap(v[v_val], v[v.size() - 1]);
        }
        v.pop_back();

        return true;
    }

    int getRandom()
    {
        // The rand() function is used in C/C++ to generate random numbers in the range [0, RAND_MAX).
        return v[rand() % v.size()];
    }
};

int main()
{
    // Main function goes here
    return 0;
}