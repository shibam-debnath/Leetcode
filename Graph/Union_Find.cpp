// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;

vector<int> parent(N), size(N);

// creates independent nodes
void make(int i)
{
    parent[i] = i;
    size[i] = 1;
}

// finds root
int find(int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

// merges
void Union(int i, int j)
{
    // find their parents first
    i = find(i);
    j = find(j);

    if (i != j)
    {
        if (size[i] < size[j])
            swap(i, j);
        // since i==largest , So it is the root
        parent[j] = i;
        // increase size of root
        size[i] += size[j];
    }

    parent[j] = i;
}

int main()
{
    // Main function goes here

    // N empires and invasions
    int n, invasion;
    cin >> n >> invasion;

    // first create independent nodes for each
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    // handle all the invasions
    for (int i = 0; i < invasion; i++)
    {
        // fight between a & b
        int a, b;
        cin >> a >> b;

        // Merge them after war
        Union(a, b);
    }

    // now find independent kings/places
    int independent = 0;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            independent++;
    }

    cout << independent << endl;

    return 0;
}